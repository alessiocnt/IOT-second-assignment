package viewer;

import java.awt.Color;
import java.awt.Font;
import java.awt.Frame;
import java.awt.GridLayout;
import java.util.*;
import javax.swing.*;
import org.knowm.xchart.*;
import org.knowm.xchart.style.markers.SeriesMarkers;

import msg.CommChannel;
import msg.SerialCommChannel;

/**
 * Create a Chart matrix
 *
 * @author timmolter
 */
public class Main {
	
	static Frame f;
	
	static JPanel p;
	
	static JLabel lblState;
	
	static JButton btnReset;
	
	private static List<Double> time = new ArrayList<>();
	private static List<Double> distance = new ArrayList<>();
	private static List<Double> speed = new ArrayList<>();
	private static List<Double> acceleration = new ArrayList<>();
	private static List<XYChart> charts;

  public static void main(String[] args) throws Exception {
	CommChannel channel = new SerialCommChannel(/*args[0]*/"COM3",9600);
	time.add((double) 0);
	distance.add((double) 0);
	speed.add((double) 0);
	acceleration.add((double) 0);
    charts = new ArrayList<XYChart>();
    charts.add(new XYChartBuilder().xAxisTitle("Time").yAxisTitle("Distance").width(600).height(400).build());
    charts.add(new XYChartBuilder().xAxisTitle("Time").yAxisTitle("Speed").width(600).height(400).build());
    charts.add(new XYChartBuilder().xAxisTitle("Time").yAxisTitle("Acceleration").width(600).height(400).build());
    XYSeries series = charts.get(0).addSeries("Distance", time, distance);
    series.setMarker(SeriesMarkers.NONE);
    series = charts.get(1).addSeries("Speed", time, speed);
    series.setMarker(SeriesMarkers.NONE);
    series = charts.get(2).addSeries("Acceleration", time, acceleration);
    series.setMarker(SeriesMarkers.NONE);
    for (XYChart chart : charts) {
      chart.getStyler().setYAxisMin((double) -10);
      chart.getStyler().setYAxisMax((double) 10);
      chart.getStyler().setLegendVisible(false);
    }
    f = new SwingWrapper<XYChart>(charts).displayChartMatrix();
    
    p = new JPanel();
    p.setLayout(new GridLayout(2, 1));
    
    lblState = new JLabel("State");
    lblState.setFont(new Font(lblState.getFont().getFontName(), Font.PLAIN, 20));
    btnReset = new JButton("Reset");
    btnReset.setFont(new Font(btnReset.getFont().getFontName(), Font.PLAIN, 20));
    btnReset.setEnabled(false);
    btnReset.addActionListener((e) -> {
    	channel.sendMsg("end");
    	time.clear();
    	distance.clear();
    	speed.clear();
    	acceleration.clear();
    });

    // add panel to frame 
    p.add(lblState); 
    p.add(btnReset);
    p.setBackground(new Color(210, 210, 210));
    f.add(p);
    // set the size of frame 
    f.setSize(1200, 800); 
    f.setTitle("Smart Exp Viewer");
    f.pack();
    f.setVisible(true); 
    String values[];
    String data[];
    String msg;
    while (true) {
    	msg = channel.receiveMsg();
    	System.out.println(msg);
    	values = msg.split(":");
    	
    	if (values[0].equals("State")) {
    		setState(values[1]);
    	} else if (values[0].equals("Data")) {
    		data = values[1].split(",");
    		setData(Double.valueOf(data[0])/1000, Double.valueOf(data[1]), Double.valueOf(data[2]), Double.valueOf(data[3]));
    	}
    }
  }
  
  public static void setState(String state) {
	  
	  lblState.setText("Current state: " + state);
	  if(state.equals("End")) {
		  btnReset.setEnabled(true);
	  } else {
		  btnReset.setEnabled(false);
	  }
	  lblState.repaint();
	  btnReset.repaint();
  }

  public static void setData(double time, double distance, double speed, double acceleration) {
	  Main.time.add(time);
	  Main.distance.add(distance);
	  Main.speed.add(speed);
	  Main.acceleration.add(acceleration);
	  charts.get(0).updateXYSeries("Distance", Main.time, Main.distance, null);
	  charts.get(1).updateXYSeries("Speed", Main.time, Main.speed, null);
	  charts.get(2).updateXYSeries("Acceleration", Main.time, Main.acceleration, null);
	  f.repaint();
  }
}