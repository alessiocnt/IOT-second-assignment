package viewer;

import msg.CommChannel;
import msg.SerialCommChannel;
import viewer.datacollector.DataCollector;
import viewer.datacollector.DataCollectorImpl;
import viewer.view.View;
import viewer.view.ViewImpl;

public class Main {
	public static void main(String[] args) throws Exception {
		CommChannel channel = new SerialCommChannel(/*args[0]*/"COM3",9600);
		View view = new ViewImpl(channel);
		DataCollector dataCollector = new DataCollectorImpl(view);
		view.setCollector(dataCollector);
		while(true) {
			String msg = channel.receiveMsg();
			System.out.println(msg);
			dataCollector.collectData(msg);
		}
	}
}
