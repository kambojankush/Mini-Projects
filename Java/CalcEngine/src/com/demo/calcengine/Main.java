package com.demo.calcengine;

public class Main {

    public static void main(String[] args) {
        
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
