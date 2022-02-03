package parser;

import document.ResultSet;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class Parser {

    private static final Logger logger = LogManager.getLogger(Parser.class);

    public static boolean isValidJSONArray(String test) {
        try {
            new JSONArray(test);
        } catch (JSONException ex1) {
            return false;
        }
        return true;
    }

    public static boolean isJSONValid(String test) {
        try {
            new JSONObject(test);
        } catch (JSONException ex) {
           return false;
        }
        return true;
    }

    public static void walk(JSONObject document, ResultSet root) {
        root.increamentFrequency();

        // For each key walk through the document
        for (String key : document.keySet()) {
            String value = document.get(key).toString();

            // Since the key is present, get child with this key
            logger.debug("Key: " + key);
            ResultSet child = root.getChild(key);

            // If it's a nested json, get the child object
            if (isJSONValid(value)) {
                JSONObject secondaryDocument = new JSONObject(value);
                walk(secondaryDocument, child);
            }
//            else if (isValidJSONArray(value)) {
//                JSONArray arrayValue = new JSONArray(value);
//                for (int i=0; i <arrayValue.length(); i++) {
//                    arrayValue.get(i);
//                }
//            }
            // TODO: Implement if json key is an array.
            // If it's a key-value pair, we need to update the value-pair
            else {
                logger.debug("Value: " + value);
                child.increamentFrequency();
                child.updateValuePair(value);
            }
        }
    }
}
