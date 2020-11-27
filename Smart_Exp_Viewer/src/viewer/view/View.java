package viewer.view;

import java.util.List;

import viewer.datacollector.DataCollector;

public interface View {
	void setData(List<Double> time, List<Double> distance, List<Double> speed, List<Double> acceleration);
	void setState(String state);
	void setCollector(DataCollector dataCollector);
	void setFreq(String string);
}
