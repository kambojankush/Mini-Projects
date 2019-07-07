package com.demo.calcengine;

public class DynamicHelper {

    private MathProcessing[] handlers;
    double leftVal, rightVal, result;

    public DynamicHelper(MathProcessing[] handlers) {
        this.handlers = handlers;
    }

    public String process(String statement) throws InvalidStatementException {
        String[] parts = statement.split(MathProcessing.SEPERATOR);
        if (parts.length != 3)
            throw new InvalidStatementException("Invalid number of fields", statement);

        String keyword = parts[0];

        MathProcessing theHandler = null;
        for (MathProcessing handler : handlers) {
            if (keyword.equalsIgnoreCase(handler.getKeyword())) {
                theHandler = handler;
                break;
            }
        }
        if (theHandler == null)
            throw new InvalidStatementException("Invalid command", statement);

        try {
            leftVal = Double.parseDouble(parts[1]);
            rightVal = Double.parseDouble(parts[2]);
        } catch (NumberFormatException e) {
            throw new InvalidStatementException("Non-numeric data", statement, e);
        }

        result = theHandler.doCalculation(leftVal, rightVal);

        StringBuilder sb = new StringBuilder(20);
        sb.append(leftVal);
        sb.append(' ');
        sb.append(theHandler.getSymbol());
        sb.append(' ');
        sb.append(rightVal);
        sb.append(" = ");
        sb.append(result);

        return sb.toString();
    }
}
