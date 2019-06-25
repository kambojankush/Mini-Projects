package com.demo.calcengine;

public class Main {

    public static void main(String[] args) {
        double[] leftVals = {100.0d, 90.0d, 120.0d, 11.0d};
        double[] rightVals = {50.0d, 10.0d, 10.0d, 3.0d};
        char[] opCodes = {'d', 'a', 's', 'm'};
        double[] results = new double[opCodes.length];

        for (int i = 0; i < opCodes.length; i++) {
            switch (opCodes[i]) {
                case 'a':
                    results[i] = leftVals[i] + rightVals[i];
                    break;
                case 's':
                    results[i] = leftVals[i] - rightVals[i];
                    break;
                case 'm': 
                    results[i] = leftVals[i] * rightVals[i];
                    break;
                case 'd': 
                    results[i] = rightVals[i] == 0.0d ? 0.0d : leftVals[i] / rightVals[i];
                    break;
                default:
                    results[i] = 0.0d;
            }
        }

        for (double resultVal : results) {
            System.out.print("result = ");
            System.out.println(resultVal);
        }
    }
}
