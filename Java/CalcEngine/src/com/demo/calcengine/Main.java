package com.demo.calcengine;

public class Main {

    public static void main(String[] args) {
        double val1 = 100.0d;
        double val2 = 50.0d;
        double result;
        char opCode = 'a';

        if (opCode == 'a')
            result = val1 + val2;
        else if (opCode == 's')
            result = val1 - val2;
        else if (opCode == 'd')
            result = (val2 == 0) ? 0.0d : val1/val2;
        else if (opCode == 'm')
            result = val1 * val2;
        else {
            System.out.println("Error: Invalid opCode");
            result = 0.0d;
        }

        System.out.println(result);
    }
}
