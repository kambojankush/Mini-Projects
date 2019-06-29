package com.demo.myapp;

import com.demo.calcengine.Adder;
import com.demo.calcengine.CalculateBase;
import com.demo.calcengine.CalculateHelper;
import com.demo.calcengine.Divider;
import com.demo.calcengine.InvalidStatementException;
import com.demo.calcengine.MathEquation;
import com.demo.calcengine.Multiplier;
import com.demo.calcengine.Subtractor;

public class Main {

    public static void main(String[] args) {
        
        // useMathEquation();
        // useInheritance();

        String[] statements = {
            "Add 1.0",
            "Add huehue 2.0",
            "AddXX 10.0 50.0",
            "Add 100.0 20.0",
            "Subtract 100.0d 20.0",
            "Divide 100.0d 0.0d",
            "Multiply 11.0 3.0"
        };

        CalculateHelper helper = new CalculateHelper();

        for (String statement : statements) { 
            try {
                helper.process(statement);
                System.out.println(helper);
            } catch (InvalidStatementException e) {
                System.out.println(e.getMessage());
                if (e.getCause() != null)
                    System.out.println("Original exception: " + e.getCause());
            }
        }
    }

    static void useMathEquation() {

        MathEquation[] equations = new MathEquation[4];
        equations[0] = new MathEquation(100.0d, 50.0d, 'd');
        equations[1] = new MathEquation(90.0d, 10.0d, 'a');
        equations[2] = new MathEquation(120.0d, 10.0d, 's');
        equations[3] = new MathEquation(11.0d, 3.0d, 'm');
        
        for (MathEquation equation : equations) {
            equation.execute();
            System.out.print("result = ");
            System.out.println(equation.getResult());
        }

        System.out.println();
        System.out.println("With Overloading");
        System.out.println();

        MathEquation overloadEquation = new MathEquation('d');
        double leftDouble = 9.0d;
        double rightDouble = 4.0d;
        overloadEquation.execute(leftDouble, rightDouble);

        System.out.print("result = ");
        System.out.println(overloadEquation.getResult());

        int leftInt = 9;
        int rightInt = 4;
        overloadEquation.execute(leftInt, rightInt);

        System.out.print("result = ");
        System.out.println(overloadEquation.getResult());
    }

    static void useInheritance() {

        System.out.println();
        System.out.println("With Inheritance: ");
        System.out.println();

        CalculateBase[] calculators = {
            new Adder(100.0d, 40.0d),
            new Subtractor(100.0d, 20.0d),
            new Divider(100.0d, 50.0d),
            new Multiplier(11.0d, 3.0d)
        };

        for (CalculateBase calculator : calculators) {
            calculator.calculate();
            System.out.print("Result = ");
            System.out.println(calculator.getResult());
        }
    }

}
