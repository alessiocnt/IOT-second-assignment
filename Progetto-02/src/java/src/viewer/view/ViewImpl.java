package viewer.view;

import java.awt.Color;
import java.awt.Font;
import java.awt.Frame;
import java.awt.GridLayout;
import java.util.*;
import javax.swing.*;
import org.knowm.xchart.*;
import org.knowm.xchart.style.markers.SeriesMarkers;
import msg.CommChannel;
import viewer.datacollector.DataCollector;

public class ViewImpl implements View {
	
	private Frame f;
	private JPanel p;
	private JLabel lblState;
	private JLabel lblFreq;
	private JButton btnReset;
	
	private DataCollector dataCollector;
	
	private List<XYChart> charts;
	
	private CommChannel channel;
	
	public ViewImpl(CommChannel channel) {
		this.channel = channel;
		this.prepareCharts();
		this.prepareGraphics();
	}
	
	private void prepareCharts() {
		List<Double> fakeData = new ArrayList<>();
		fakeData.add((double) 0);
		this.charts = new ArrayList<XYChart>();
		this.charts.add(new XYChartBuilder().xAxisTitle("Time").yAxisTitle("Distance").width(600).height(400).build());
		this.charts.add(new XYChartBuilder().xAxisTitle("Time").yAxisTitle("Speed").width(600).height(400).build());
		this.charts.add(new XYChartBuilder().xAxisTitle("Time").yAxisTitle("Acceleration").width(600).height(400).build());
	    XYSeries series = this.charts.get(0).addSeries("Distance", null, fakeData);
	    series.setMarker(SeriesMarkers.NONE);
	    series = this.charts.get(1).addSeries("Speed", null, fakeData);
	    series.setMarker(SeriesMarkers.NONE);
	    series = this.charts.get(2).addSeries("Acceleration", null, fakeData);
	    series.setMarker(SeriesMarkers.NONE);
	    for (XYChart chart : this.charts) {
	    	chart.getStyler().setYAxisMin((double) -10);
	    	chart.getStyler().setYAxisMax((double) 10);
	    	chart.getStyler().setLegendVisible(false);
	    }
	}
	
	private void prepareGraphics() {
		this.f = new SwingWrapper<XYChart>(this.charts).displayChartMatrix();
		this.p = new JPanel();
		this.p.setLayout(new GridLayout(2, 1));
	    JPanel p1 = new JPanel();
	    p1.setLayout(new GridLayout(1, 2));
		this.lblState = new JLabel("State");
		this.lblState.setFont(new Font(this.lblState.getFont().getFontName(), Font.PLAIN, 20));
		this.lblFreq = new JLabel("");
		this.lblFreq.setFont(new Font(this.lblFreq.getFont().getFontName(), Font.PLAIN, 20));
		this.btnReset = new JButton("Reset");
		this.btnReset.setFont(new Font(this.btnReset.getFont().getFontName(), Font.PLAIN, 20));
		this.btnReset.setEnabled(false);
		this.btnReset.addActionListener((e) -> {
	    	this.channel.sendMsg("end");
	    	this.lblFreq.setText("");
	    	this.dataCollector.reset();
	    });
	    // add panel to frame 
		p1.add(lblState);
		p1.add(lblFreq);
	    this.p.add(p1); 
	    this.p.add(this.btnReset);
	    this.p.setBackground(new Color(210, 210, 210));
	    this.f.add(this.p);
	    // set the size of frame 
	    this.f.setSize(1200, 800); 
	    this.f.setTitle("Smart Exp Viewer");
	    this.f.pack();
	    this.f.setVisible(true); 
	}

	@Override
	public void setData(List<Double> time, List<Double> distance, List<Double> speed, List<Double> acceleration) {
		charts.get(0).updateXYSeries("Distance", time, distance, null);
	    charts.get(1).updateXYSeries("Speed", time, speed, null);
	    charts.get(2).updateXYSeries("Acceleration", time, acceleration, null);
	    f.repaint();
	}

	@Override
	public void setState(String state) {
		this.lblState.setText("Current state: " + state);
		if(state.equals("End")) {
			this.btnReset.setEnabled(true);
		} else {
			this.btnReset.setEnabled(false);
		}
		this.lblState.repaint();
		this.btnReset.repaint();
	}

	@Override
	public void setCollector(DataCollector dataCollector) {
		this.dataCollector = dataCollector;
	}

	@Override
	public void setFreq(String freq) {
		this.lblFreq.setText("Sampling freq: " + freq + "Hz");
	}
}