package com.rockwellcollins.atc.resolute.analysis.values;

public class IntValue extends ResoluteValue {
    final private long value;

    public IntValue(long value) {
        this.value = value;
    }

    @Override
    public boolean isInt() {
        return true;
    }

    @Override
    public long getInt() {
        return value;
    }

    @Override
    public String toString() {
        return Long.toString(value);
    }

    @Override
    public int hashCode() {
        return new Long(value).hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof IntValue) {
            IntValue iv = (IntValue) obj;
            return iv.value == value;
        }

        return false;
    }
}
