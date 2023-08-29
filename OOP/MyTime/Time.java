package MyTime;

public class Time {
    private int hour, mins, secs;
    private boolean meridian;

    public Time(int hour, int mins, int secs, boolean meridian) {
        this.hour = hour;
        this.mins = mins;
        this.secs = secs;
        this.meridian = meridian;
    }

    public int getHour() {
        return hour;
    }

    public int getMins() {
        return mins;
    }

    public int getSecs() {
        return secs;
    }

    public boolean isMeridian() {
        return meridian;
    }

}
