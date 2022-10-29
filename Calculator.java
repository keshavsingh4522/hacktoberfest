import javax.swing.*;
import org.w3c.dom.css.RGBColor;

import java.util.Scanner;
import java.awt.*;
import java.awt.event.*;

class Calculator implements ActionListener {

    JFrame f;
    JTextField t1, t2, t3;
    JButton b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, badd, bsub, bmul, bdiv, beq, bdel, bdec, bclr;
    static double a = 0, b = 0, result = 0;
    static int operator = 0;

    Calculator() {
        f = new JFrame("CALCULATOR");
        f.setVisible(true);
        f.setLayout(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        f.setBounds(50, 50, 300, 350);
        f.setResizable(false);
        Font fo = new Font("Arial", Font.BOLD, 20);
        t1 = new JTextField();
        t1.setBounds(40, 40, 200, 50);
        t1.setBackground(Color.GRAY);
        t1.setForeground(Color.RED);
        t1.setFont(fo);

        b1 = new JButton("1");

        b1.setFont(fo);

        b2 = new JButton("2");

        b2.setFont(fo);

        b3 = new JButton("3");

        b3.setFont(fo);

        b4 = new JButton("4");

        b4.setFont(fo);

        b5 = new JButton("5");

        b5.setFont(fo);

        b6 = new JButton("6");

        b6.setFont(fo);

        b7 = new JButton("7");

        b7.setFont(fo);

        b8 = new JButton("8");

        b8.setFont(fo);

        b9 = new JButton("9");

        b9.setFont(fo);

        b0 = new JButton("0");

        b0.setFont(fo);

        badd = new JButton("+");

        badd.setFont(fo);

        bsub = new JButton("-");

        bsub.setFont(fo);

        bmul = new JButton("*");

        bmul.setFont(fo);

        bdiv = new JButton("/");

        bdiv.setFont(fo);

        beq = new JButton("=");

        beq.setFont(fo);

        bclr = new JButton("Clear");

        bclr.setFont(fo);

        bdel = new JButton("Delete");

        bdel.setFont(fo);

        bdec = new JButton(".");

        bdec.setFont(fo);

        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener(this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
        b0.addActionListener(this);
        badd.addActionListener(this);
        bsub.addActionListener(this);
        bdel.addActionListener(this);
        bdiv.addActionListener(this);
        beq.addActionListener(this);
        bdec.addActionListener(this);
         bmul.addActionListener(this);
         bclr.addActionListener(this);

    

        b7.setBounds(40, 100, 50, 40);
        b8.setBounds(90, 100, 50, 40);
        b9.setBounds(140, 100, 50, 40);
        bdiv.setBounds(190, 100, 50, 40);

        b4.setBounds(40, 140, 50, 40);
        b5.setBounds(90, 140, 50, 40);
        b6.setBounds(140, 140, 50, 40);
        bsub.setBounds(190, 140, 50, 40);

        b1.setBounds(40, 180, 50, 40);
        b2.setBounds(90, 180, 50, 40);
        b3.setBounds(140, 180, 50, 40);
        badd.setBounds(190, 180, 50, 40);

        beq.setBounds(40, 220, 50, 40);
        b0.setBounds(90, 220, 50, 40);
        bdec.setBounds(140, 220, 50, 40);
        bmul.setBounds(190, 220, 50, 40);

        bdel.setBounds(40, 260, 100, 40);
        bclr.setBounds(140, 260, 100, 40);

        f.add(t1);
        f.add(b1);

        f.add(b2);
        f.add(b3);
        f.add(b4);
        f.add(b5);
        f.add(b6);
        f.add(b7);
        f.add(b8);
        f.add(b9);
        f.add(b0);
        f.add(badd);
        f.add(bsub);
        f.add(bdiv);
        f.add(bmul);
        f.add(beq);
        f.add(bdel);

        f.add(bclr);

        f.add(bdec);
        f.add(bdec);

    }

    public static void main(String arg[]) {

        new Calculator();
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == bclr) {
            t1.setText("");
        }
        if (e.getSource() == bdel) {
            String s= t1.getText();
            t1.setText("");
            for(int i=0;i<s.length()-1;i++){
                t1.setText(t1.getText()+s.charAt(i));
            }
        }
        if (e.getSource() == b1) {
            t1.setText(t1.getText().concat("1"));
        }
        if (e.getSource() == b2) {
            t1.setText(t1.getText().concat("2"));
        }
        if (e.getSource() == b3) {
            t1.setText(t1.getText().concat("3"));
        }

        if (e.getSource() == b4) {
            t1.setText(t1.getText().concat("4"));
        }
        if (e.getSource() == b5) {
            t1.setText(t1.getText().concat("5"));
        }

        if (e.getSource() == b6) {
            t1.setText(t1.getText().concat("6"));
        }
        if (e.getSource() == b7) {
            t1.setText(t1.getText().concat("7"));
        }
        if (e.getSource() == b8) {
            t1.setText(t1.getText().concat("8"));
        }
        if (e.getSource() == b9) {
            t1.setText(t1.getText().concat("9"));
        }
        if (e.getSource() == b0) {
            t1.setText(t1.getText().concat("0"));
        }
        if (e.getSource() == bdec) {
            t1.setText(t1.getText().concat("."));
        }

        if (e.getSource() == badd) {
            a = Double.parseDouble(t1.getText());
            operator = 1;
            t1.setText("");

        }
        if (e.getSource() == bsub) {
            a = Double.parseDouble(t1.getText());
            operator = 2;
            t1.setText("");

        }
        if (e.getSource() == bdiv) {
            a = Double.parseDouble(t1.getText());
            operator = 3;
            t1.setText("");

        }
        if (e.getSource() == bmul) {
            a = Double.parseDouble(t1.getText());
            operator = 4;
            t1.setText("");

        }
        if (e.getSource() == beq) {
            b = Double.parseDouble(t1.getText());
            switch (operator) {
case 1: result=a+b;
break;
case 2: result=a-b;
break;

case 3: result=a/b;
break;

case 4: result=a*b;
break;


            }
            t1.setText(""+result);

        }

    }

}
