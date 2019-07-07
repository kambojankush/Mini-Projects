package com.demo.calcengine;

public class Divider extends CalculateBase implements MathProcessing {

	public Divider() {}
	public Divider(double leftVal, double rightVal) {
		super(leftVal, rightVal);
	}

	@Override
	public void calculate() {
		double value = getRightVal() == 0.0d ? 0.0d : getLeftVal() / getRightVal();
		setResult(value);
	}

	@Override
	public String getKeyword() {
		return "Divide";
	}

	@Override
	public char getSymbol() {
		return '/';
	}

	@Override
	public double doCalculation(double leftVal, double rightVal) {
		setLeftVal(leftVal);
		setRightVal(rightVal);
		calculate();
		return getResult();
	}
}