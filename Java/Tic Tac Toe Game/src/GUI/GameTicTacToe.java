/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GUI;

import java.awt.Color;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

/**
 *
 * @author ALI
 */
public class GameTicTacToe extends javax.swing.JFrame {

    
    
    /**
     * Creates new form GameTicTacToe
     */
    public GameTicTacToe() {
        initComponents();
    }
    private String gameStart = "X";
    private int turn=0;
    
    public void playerTurn(){
        if(gameStart.equalsIgnoreCase("X")){
            gameStart = "O";
            labelTurn.setText("Player Two's Turn");
            turn += 1;
        }else{
            gameStart = "X";
            labelTurn.setText("Player One's Turn");
            turn += 1;
        }
        if(turn ==9 ){
            if(cek == 3){
            JOptionPane.showMessageDialog(this, "its Draww", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
            }
            turn =0;
        }
        
    }
    
    private int cek = 0;
    
    public void winnerGame(){
        String b1 = btn1.getText();
        String b2 = btn2.getText();
        String b3 = btn3.getText();
        String b4 = btn4.getText();
        String b5 = btn5.getText();
        String b6 = btn6.getText();
        String b7 = btn7.getText();
        String b8 = btn8.getText();
        String b9 = btn9.getText();
        
        //Player One WINNERR
        if(b1 == "X" && b2 == "X" && b3 == "X"){
             JOptionPane.showMessageDialog(this, "Player One's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn1.setBackground(Color.YELLOW);
             btn2.setBackground(Color.YELLOW);
             btn3.setBackground(Color.YELLOW);
             cek = 1;
        }else if(b4 == "X" && b5 == "X" && b6 == "X"){
             JOptionPane.showMessageDialog(this, "Player One's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn4.setBackground(Color.YELLOW);
             btn5.setBackground(Color.YELLOW);
             btn6.setBackground(Color.YELLOW);
             cek = 1;
        }else if(b7 == "X" && b8 == "X" && b9 == "X"){
             JOptionPane.showMessageDialog(this, "Player One's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn7.setBackground(Color.YELLOW);
             btn8.setBackground(Color.YELLOW);
             btn9.setBackground(Color.YELLOW);
             cek = 1;
        }else if(b1 == "X" && b4 == "X" && b7 == "X"){
             JOptionPane.showMessageDialog(this, "Player One's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn1.setBackground(Color.YELLOW);
             btn4.setBackground(Color.YELLOW);
             btn7.setBackground(Color.YELLOW);
             cek = 1;
        }else if(b2 == "X" && b5 == "X" && b8 == "X"){
             JOptionPane.showMessageDialog(this, "Player One's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn2.setBackground(Color.YELLOW);
             btn5.setBackground(Color.YELLOW);
             btn8.setBackground(Color.YELLOW);
             cek = 1;
        }else if(b3 == "X" && b6 == "X" && b9 == "X"){
             JOptionPane.showMessageDialog(this, "Player One's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn3.setBackground(Color.YELLOW);
             btn6.setBackground(Color.YELLOW);
             btn9.setBackground(Color.YELLOW);
             cek = 1;
        }else if(b1 == "X" && b5 == "X" && b9 == "X"){
             JOptionPane.showMessageDialog(this, "Player One's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn1.setBackground(Color.YELLOW);
             btn5.setBackground(Color.YELLOW);
             btn9.setBackground(Color.YELLOW);
             cek = 1;
        }else if(b3 == "X" && b5 == "X" && b7 == "X"){
             JOptionPane.showMessageDialog(this, "Player One's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn3.setBackground(Color.YELLOW);
             btn5.setBackground(Color.YELLOW);
             btn7.setBackground(Color.YELLOW);
             cek = 1;
        }else{
            cek =3;
        }
        
        //Player Two WINNERR
        if(b1 == "O" && b2 == "O" && b3 == "O"){
             JOptionPane.showMessageDialog(this, "Player Two's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn1.setBackground(Color.YELLOW);
             btn2.setBackground(Color.YELLOW);
             btn3.setBackground(Color.YELLOW);
             cek = 2;
        }else if(b4 == "O" && b5 == "O" && b6 == "O"){
             JOptionPane.showMessageDialog(this, "Player Two's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn4.setBackground(Color.YELLOW);
             btn5.setBackground(Color.YELLOW);
             btn6.setBackground(Color.YELLOW);
             cek = 2;
        }else if(b7 == "O" && b8 == "O" && b9 == "O"){
             JOptionPane.showMessageDialog(this, "Player Two's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn7.setBackground(Color.YELLOW);
             btn8.setBackground(Color.YELLOW);
             btn9.setBackground(Color.YELLOW);
             cek = 2;
        }else if(b1 == "O" && b4 == "O" && b7 == "O"){
             JOptionPane.showMessageDialog(this, "Player Two's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn1.setBackground(Color.YELLOW);
             btn4.setBackground(Color.YELLOW);
             btn7.setBackground(Color.YELLOW);
             cek = 2;
        }else if(b2 == "O" && b5 == "O" && b8 == "O"){
             JOptionPane.showMessageDialog(this, "Player Two's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn2.setBackground(Color.YELLOW);
             btn5.setBackground(Color.YELLOW);
             btn8.setBackground(Color.YELLOW);
             cek = 2;
        }else if(b3 == "O" && b6 == "O" && b9 == "O"){
             JOptionPane.showMessageDialog(this, "Player Two's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn3.setBackground(Color.YELLOW);
             btn6.setBackground(Color.YELLOW);
             btn9.setBackground(Color.YELLOW);
             cek = 2;
        }else if(b1 == "O" && b5 == "O" && b9 == "O"){
             JOptionPane.showMessageDialog(this, "Player Two's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn1.setBackground(Color.YELLOW);
             btn5.setBackground(Color.YELLOW);
             btn9.setBackground(Color.YELLOW);
             cek = 2;
        }else if(b3 == "O" && b5 == "O" && b7 == "O"){
             JOptionPane.showMessageDialog(this, "Player Two's Winn", "Tic Tac Toe",
                     JOptionPane.INFORMATION_MESSAGE);
             btn3.setBackground(Color.YELLOW);
             btn5.setBackground(Color.YELLOW);
             btn7.setBackground(Color.YELLOW);
             cek = 2;
        }else{
            cek = 3;
        }
    }
    


    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jMenuItem1 = new javax.swing.JMenuItem();
        jMenuBar2 = new javax.swing.JMenuBar();
        jMenu2 = new javax.swing.JMenu();
        jMenu3 = new javax.swing.JMenu();
        btn1 = new javax.swing.JButton();
        btn2 = new javax.swing.JButton();
        btn3 = new javax.swing.JButton();
        btn4 = new javax.swing.JButton();
        btn5 = new javax.swing.JButton();
        btn6 = new javax.swing.JButton();
        btn7 = new javax.swing.JButton();
        btn8 = new javax.swing.JButton();
        btn9 = new javax.swing.JButton();
        labelTurn = new javax.swing.JLabel();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        newGame = new javax.swing.JMenuItem();
        Exit = new javax.swing.JMenuItem();

        jMenuItem1.setText("jMenuItem1");

        jMenu2.setText("File");
        jMenuBar2.add(jMenu2);

        jMenu3.setText("Edit");
        jMenuBar2.add(jMenu3);

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Tic Tac Toe");

        btn1.setFont(new java.awt.Font("Segoe UI", 1, 36)); // NOI18N
        btn1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn1ActionPerformed(evt);
            }
        });

        btn2.setFont(new java.awt.Font("Segoe UI", 1, 36)); // NOI18N
        btn2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn2ActionPerformed(evt);
            }
        });

        btn3.setFont(new java.awt.Font("Segoe UI", 1, 36)); // NOI18N
        btn3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn3ActionPerformed(evt);
            }
        });

        btn4.setFont(new java.awt.Font("Segoe UI", 1, 36)); // NOI18N
        btn4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn4ActionPerformed(evt);
            }
        });

        btn5.setFont(new java.awt.Font("Segoe UI", 1, 36)); // NOI18N
        btn5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn5ActionPerformed(evt);
            }
        });

        btn6.setFont(new java.awt.Font("Segoe UI", 1, 36)); // NOI18N
        btn6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn6ActionPerformed(evt);
            }
        });

        btn7.setFont(new java.awt.Font("Segoe UI", 1, 36)); // NOI18N
        btn7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn7ActionPerformed(evt);
            }
        });

        btn8.setFont(new java.awt.Font("Segoe UI", 1, 36)); // NOI18N
        btn8.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn8ActionPerformed(evt);
            }
        });

        btn9.setFont(new java.awt.Font("Segoe UI", 1, 36)); // NOI18N
        btn9.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn9ActionPerformed(evt);
            }
        });

        labelTurn.setText("Player One's Turn");

        jMenu1.setText("Menu Game");

        newGame.setText("New Game");
        newGame.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                newGameActionPerformed(evt);
            }
        });
        jMenu1.add(newGame);

        Exit.setText("Exit");
        Exit.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ExitActionPerformed(evt);
            }
        });
        jMenu1.add(Exit);

        jMenuBar1.add(jMenu1);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(btn1, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btn2, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btn3, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(btn4, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btn5, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btn6, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(btn7, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btn8, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btn9, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(labelTurn, javax.swing.GroupLayout.PREFERRED_SIZE, 119, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(btn1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btn3, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btn2, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(btn4, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btn6, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btn5, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(btn7, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btn9, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btn8, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(labelTurn, javax.swing.GroupLayout.DEFAULT_SIZE, 24, Short.MAX_VALUE)
                .addContainerGap())
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void ExitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ExitActionPerformed
        int exit = JOptionPane.showConfirmDialog(
        null,
                "Yakin Berhenti Bermain?",
                "Tic Tac Toe",
                JOptionPane.YES_NO_OPTION);
        if(exit == JOptionPane.YES_OPTION){
            System.exit(0);
        }
    }//GEN-LAST:event_ExitActionPerformed

    private void btn1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn1ActionPerformed
        btn1.setText(gameStart);
        
        if(gameStart.equalsIgnoreCase("X")){
            btn1.setForeground(Color.BLUE);
        }else{
            btn1.setForeground(Color.RED);
        }
        playerTurn();
        winnerGame();
    }//GEN-LAST:event_btn1ActionPerformed

    private void btn2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn2ActionPerformed
        btn2.setText(gameStart);
        
        if(gameStart.equalsIgnoreCase("X")){
            btn2.setForeground(Color.BLUE);
        }else{
            btn2.setForeground(Color.RED);
        }
        playerTurn();
        winnerGame();
    }//GEN-LAST:event_btn2ActionPerformed

    private void btn3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn3ActionPerformed
        btn3.setText(gameStart);
        
        if(gameStart.equalsIgnoreCase("X")){
            btn3.setForeground(Color.BLUE);
        }else{
            btn3.setForeground(Color.RED);
        }
        playerTurn();
        winnerGame();
    }//GEN-LAST:event_btn3ActionPerformed

    private void btn4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn4ActionPerformed
        btn4.setText(gameStart);
        
        if(gameStart.equalsIgnoreCase("X")){
            btn4.setForeground(Color.BLUE);
        }else{
            btn4.setForeground(Color.RED);
        }
        playerTurn();
        winnerGame();
    }//GEN-LAST:event_btn4ActionPerformed

    private void btn5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn5ActionPerformed
        btn5.setText(gameStart);
        
        if(gameStart.equalsIgnoreCase("X")){
            btn5.setForeground(Color.BLUE);
        }else{
            btn5.setForeground(Color.RED);
        }
        playerTurn();
        winnerGame();
    }//GEN-LAST:event_btn5ActionPerformed

    private void btn6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn6ActionPerformed
        btn6.setText(gameStart);
        
        if(gameStart.equalsIgnoreCase("X")){
            btn6.setForeground(Color.BLUE);
        }else{
            btn6.setForeground(Color.RED);
        }
        playerTurn();
        winnerGame();
    }//GEN-LAST:event_btn6ActionPerformed

    private void btn7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn7ActionPerformed
        btn7.setText(gameStart);
        
        if(gameStart.equalsIgnoreCase("X")){
            btn7.setForeground(Color.BLUE);
        }else{
            btn7.setForeground(Color.RED);
        }
        playerTurn();
        winnerGame();
    }//GEN-LAST:event_btn7ActionPerformed

    private void btn8ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn8ActionPerformed
        btn8.setText(gameStart);
        
        if(gameStart.equalsIgnoreCase("X")){
            btn8.setForeground(Color.BLUE);
        }else{
            btn8.setForeground(Color.RED);
        }
        playerTurn();
        winnerGame();
    }//GEN-LAST:event_btn8ActionPerformed

    private void btn9ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn9ActionPerformed
        btn9.setText(gameStart);
        
        if(gameStart.equalsIgnoreCase("X")){
            btn9.setForeground(Color.BLUE);
        }else{
            btn9.setForeground(Color.RED);
        }
        playerTurn();
        winnerGame();
    }//GEN-LAST:event_btn9ActionPerformed

    private void newGameActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_newGameActionPerformed
        btn1.setText(null);
        btn2.setText(null);
        btn3.setText(null);
        btn4.setText(null);
        btn5.setText(null);
        btn6.setText(null);
        btn7.setText(null);
        btn8.setText(null);
        btn9.setText(null);
        
        btn1.setBackground(Color.LIGHT_GRAY);
        btn2.setBackground(Color.LIGHT_GRAY);
        btn3.setBackground(Color.LIGHT_GRAY);
	btn4.setBackground(Color.LIGHT_GRAY);
        btn5.setBackground(Color.LIGHT_GRAY);
        btn6.setBackground(Color.LIGHT_GRAY);
	btn7.setBackground(Color.LIGHT_GRAY);
        btn8.setBackground(Color.LIGHT_GRAY);
        btn9.setBackground(Color.LIGHT_GRAY);
        turn = 0;
    }//GEN-LAST:event_newGameActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(GameTicTacToe.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(GameTicTacToe.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(GameTicTacToe.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(GameTicTacToe.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new GameTicTacToe().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuItem Exit;
    private javax.swing.JButton btn1;
    private javax.swing.JButton btn2;
    private javax.swing.JButton btn3;
    private javax.swing.JButton btn4;
    private javax.swing.JButton btn5;
    private javax.swing.JButton btn6;
    private javax.swing.JButton btn7;
    private javax.swing.JButton btn8;
    private javax.swing.JButton btn9;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenu jMenu3;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuBar jMenuBar2;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JLabel labelTurn;
    private javax.swing.JMenuItem newGame;
    // End of variables declaration//GEN-END:variables
}
