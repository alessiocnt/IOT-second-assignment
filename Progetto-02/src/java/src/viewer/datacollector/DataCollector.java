package viewer.datacollector;

/**
 * Models a DataCollector.
 */
public interface DataCollector {
	/**
	 * Allows the collection of data received from serial port.
	 * @param data the data to collect
	 */
	void collectData(String data);

	void reset();
}
