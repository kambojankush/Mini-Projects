package com.demo.calcengine;

public class MathEquation {

	public double leftVal, rightVal, result;
	public char opCode;

	public void execute() {
		switch (opCode) {
			case 'a':
				result = leftVal + rightVal;
				break;
			case 's':
				result = leftVal - rightVal;
				break;
			case 'd':
				result = rightVal == 0.0d ? 0.0d : leftVal / rightVal;
				break;
			case 'm':
				result = leftVal * rightVal;
				break;
			default:
				System.out.println("Invalid OpCode");
				result = 0.0d;
		}
	}
}