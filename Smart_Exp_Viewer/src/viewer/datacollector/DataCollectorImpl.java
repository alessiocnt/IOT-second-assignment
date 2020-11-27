package viewer.datacollector;

import java.util.ArrayList;
import java.util.List;

import viewer.view.View;

public class DataCollectorImpl implements DataCollector {

	private View view;
	private List<Double> time = new ArrayList<>();
	private List<Double> distance = new ArrayList<>();
	private List<Double> speed = new ArrayList<>();
	private List<Double> acceleration = new ArrayList<>();
	
	public DataCollectorImpl(View view) {
		this.view = view;
		this.time.add((double) 0);
		this.distance.add((double) 0);
		this.speed.add((double) 0);
		this.acceleration.add((double) 0);
		this.view.setData(this.time, this.distance, this.speed, this.acceleration);
	}
	
	@Override
	public final void collectData(String data) {
		String values[] = data.split(":");
	    
	    if (values[0].equals("State")) {
    		view.setState(values[1]);
    	} else if (values[0].equals("Data")) {
    		String results[] = values[1].split(",");
    		this.setData(results);
    	}
		
	}
	
	private void setData(String[] data) {
		this.time.add(Double.valueOf(data[0])/1000);
		this.distance.add(Double.valueOf(data[1]));
		this.speed.add(Double.valueOf(data[2]));
		this.acceleration.add(Double.valueOf(data[3]));
		this.view.setData(this.time, this.distance, this.speed, this.acceleration);
	}

	@Override
	public void reset() {
		this.time.clear();
		this.distance.clear();
		this.speed.clear();
		this.acceleration.clear();
	}
	
	

}
