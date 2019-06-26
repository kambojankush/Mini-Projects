package com.demo.calcengine;

public class MathEquation {

	private double leftVal, rightVal, result;
	private char opCode;

	public double getLeftVal() {return leftVal;}
	public void setLeftVal(double leftVal) {this.leftVal = leftVal;}
	public double getRightVal() {return rightVal;}
	public void setRightVal(double rightVal) {this.rightVal = rightVal;}
	public char getOpCode() {return opCode;}
	public void setOpCode(char opCode) {this.opCode = opCode;}

	public double getResult() {return result;}

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