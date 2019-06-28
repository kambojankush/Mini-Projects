package com.demo.calcengine;

public class Divider extends CalculateBase {

	public Divider() {}
	public Divider(double leftVal, double rightVal) {
		super(leftVal, rightVal);
	}

	@Override
	public void calculate() {
		double value = getRightVal() == 0.0d ? 0.0d : getLeftVal() / getRightVal();
		setResult(value);
	}
}