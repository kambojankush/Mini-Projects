package com.demo.calcengine;

public class CalculateHelper {

	double leftVal, rightVal, result;
	MathCommand command;

	public void process(String statement) {

		String[] parts = statement.split(" ");
		String commandString = parts[0];
		leftVal = Double.parseDouble(parts[1]);
		rightVal = Double.parseDouble(parts[2]);

		setCommandFromString(commandString);
		CalculateBase calculator = null;

		switch (command) {
			case Add:
				calculator = new Adder(leftVal, rightVal);
				break;
			case Subtract:
				calculator = new Subtractor(leftVal, rightVal);
				break;
			case Divide:
				calculator = new Divider(leftVal, rightVal);
				break;
			case Multiply:
				calculator = new Multiplier(leftVal, rightVal);
				break;
		}

		calculator.calculate();
		result = calculator.getResult();
	}

	private void setCommandFromString(String commandString) {

		if (commandString.equalsIgnoreCase(MathCommand.Add.toString()))
			command = MathCommand.Add;
		else if (commandString.equalsIgnoreCase(MathCommand.Subtract.toString()))
			command = MathCommand.Subtract;
		else if (commandString.equalsIgnoreCase(MathCommand.Divide.toString()))
			command = MathCommand.Divide;
		else if (commandString.equalsIgnoreCase(MathCommand.Multiply.toString()))
			command = MathCommand.Multiply;
	}
}