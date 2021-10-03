import java.awt.*;
import java.awt.event.InputEvent;

/**
* A Robot mouse clicker that automatically clicks the mouse button so that the computer doesn't go to sleep.
**/
public class Robo {

    public static void main(String args[]) {
	int timeInSecs = 15;
        try {
            Robot robot = new Robot();
            Runnable runnable = new Runnable() {
                @Override
                public void run() {
                    while(true) {
                        try {
                            Thread.sleep(timeInSecs * 1000);
                        } catch(InterruptedException e) {
                            e.printStackTrace();
                        } finally {
                            robot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
                            robot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
                        }
                    }
                }
            };

            Thread thread = new Thread(runnable);
            thread.run();

        } catch(AWTException e) {
            e.printStackTrace();
        }

    }
}
