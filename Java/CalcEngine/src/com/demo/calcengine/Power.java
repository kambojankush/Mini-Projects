package com.demo.calcengine;

public class Power extends CalculateBase implements MathProcessing {

    public Power() {}
    public Power(double leftVal, double rightVal) { super(leftVal, rightVal); }

    @Override
    public void calculate() {
        double value = Math.pow(getLeftVal(), getRightVal());
        setResult(value);
    }

    @Override
    public String getKeyword() {
        return "Power";
    }

    @Override
    public char getSymbol() {
        return '^';
    }

    @Override
    public double doCalculation(double leftVal, double rightVal) {
        setLeftVal(leftVal);
        setRightVal(rightVal);
        calculate();
        return getResult();
    }
}
