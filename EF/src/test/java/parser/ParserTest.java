package parser;

import document.ResultSet;
import org.json.JSONObject;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ParserTest {

    @Test
    void walkTest() {
        JSONObject obj = new JSONObject("{“name” : “Joe”, “address” : {“street” : “montgomery st”, “number”: 101, “city”: “new york”, “state”: “ny”}}");
        ResultSet rs = new ResultSet("root");
        Parser.walk(obj, rs);

        JSONObject obj2 = new JSONObject("{“name” : “Evan”, “address” : {“street” : “Santa Theresa st”, “number”: 201, “city”: “sfo”, “state”: “ca”}}");
        JSONObject obj3 = new JSONObject("{“name” : “Joe”, “address” : {“street” : “new hampshire ave”, “number”: 301, “city”: “dublin”, “state”: “ca”}}");
        JSONObject obj4 = new JSONObject("{“name” : “Joe”, “address” : {“street” : “Santa Theresa st”}}");
        Parser.walk(obj2, rs);
        Parser.walk(obj3, rs);
        Parser.walk(obj4, rs);

        rs.print();
    }

    @Test
    void walkTest2() {
        JSONObject obj = new JSONObject("{“qualifications” : [“MS”, “BS”] }");
//        ResultSet rs = new ResultSet("root");
//        Parser.walk(obj, rs);
//        rs.print();

        System.out.println(Parser.isValidJSONArray("[“MS”, “BS”]"));
        System.out.println(Parser.isValidJSONArray("{“street” : “Santa Theresa st”}"));
//        rs.print();
    }

}