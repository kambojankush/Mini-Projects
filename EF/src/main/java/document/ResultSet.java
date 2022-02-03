package document;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.json.*;

public class ResultSet {
    private static final Logger logger = LogManager.getLogger(ResultSet.class);

    public String id;
    public int frequency;
    public Map<String, Integer> valuePair;
    public Map<String, ResultSet> children;
    public ResultSet parent;

    public ResultSet(String id) {
        this.id = id;
        this.frequency = 0;
        this.valuePair = new TreeMap<>();
        this.children = new HashMap<>();
        this.parent = null;
    }

    public ResultSet(String id, ResultSet parent) {
        this.id = id;
        this.frequency = 0;
        this.valuePair = new TreeMap<>();
        this.children = new HashMap<>();
        this.parent = parent;
    }

    public int increamentFrequency() {
        return ++frequency;
    }

    // For updating for type leaf
    public void updateValuePair(String key) {
        valuePair.put(key, valuePair.getOrDefault(key,0)+1);
    }

    public ResultSet getChild(String key) {
        if (children.containsKey(key)) return children.get(key);
        ResultSet child = new ResultSet(key, this);
        this.children.put(key, child);
        return child;
    }

    public double getPercentage() {
        Double parentFreq = (this.parent != null) ? Double.valueOf(this.parent.frequency) : this.frequency;
        return this.frequency/parentFreq;
    }

    // TODO: Overall frequency

    public double getValuePairPercentage(String key) {
        double valueFrequency = valuePair.getOrDefault(key, 0);
        return valueFrequency / this.frequency;
    }

//    public List<Pair<String, int>>

    @Override
    public String toString() {
        return "ResultSet{" +
                "id='" + id + '\'' +
                '}';
    }

    public void print() {
        logger.warn("ID: " + this.id + ", Frequency = " + this.frequency + ", Percentage: " + this.getPercentage() + ", Parent : " + this.parent);
        for (Map.Entry<String, Integer> entry : valuePair.entrySet()) {
            String k = entry.getKey();
            int value = entry.getValue();
            logger.warn("        " + k + ":" + getValuePairPercentage(k) + ", count = " + value);
        }

        for (Map.Entry<String, ResultSet> entry : children.entrySet()) {
            logger.warn("Calling child: " + entry.getKey());
            entry.getValue().print();
        }

    }
}
