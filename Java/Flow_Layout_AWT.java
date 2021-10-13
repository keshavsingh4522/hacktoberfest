import java.awt.Button;
import java.awt.Frame;

public class FlowLayout {
    public static void main(String[] args) {
        Frame frame = new Frame("Flow Layout");

        frame.setVisible(true);
        frame.setSize(600, 600);

        frame.setLayout(null);

        frame.add(new Button("Button 1"));
        frame.add(new Button("Button 2"));
        frame.add(new Button("Button 3"));
        frame.add(new Button("Button 4"));
        frame.add(new Button("Button 5"));
        frame.add(new Button("Button 6"));
    }
}
