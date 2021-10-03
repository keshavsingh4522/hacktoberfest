import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JDesktopPane;
import javax.swing.JFrame;
import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class App extends JFrame{

    final static String StringDriver = "com.mysql.cj.jdbc.Driver",
                        StringConnection = "jdbc:mysql://localhost:3306/sensus",
                        StringTabelRT = "data_rt",
                        StringTabelRW = "data_rw",
                        StringTabelDP = "data_penduduk",
                        StringTabelDPT = "data_petugas",
                        StringConnectionUser = "root",
                        StringConnectionPass = "";
                        
    private static Connection conn = null;

    private static JDesktopPane frmMDI = new JDesktopPane();

    private static JInternalFrame   formDataRT,
                                    formDataRW,
                                    formDetailPenduduk,
                                    formDataPetugas;

    private static JPanel   pnlDataRT,
                            pnlDataRW,
                            pnlDetailPenduduk,
                            pnlDetailPetugas;

    private static JMenuBar MenuBar = new JMenuBar();
    private static JMenu MenuMaster = new JMenu("Master Data");

    private static JMenuItem    subMenuMDDataRT = new JMenuItem("Data RT"),
                                subMenuMDDataRW = new JMenuItem("Data RW"),
                                subMenuMDDetailPenduduk = new JMenuItem("Detail Penduduk"),
                                subMenuMDDataPetugas = new JMenuItem("Data Petugas"),
                                MenuExit = new JMenuItem("Exit");

    private static JLabel   lblDataRT_KodeRT = new JLabel(),
                            lblDataRT_NamaRT = new JLabel(),
                            lblDataRT_JumlahRT = new JLabel(),
                            
                            lblDataRW_KodeRW  = new JLabel(),
                            lblDataRW_NamaRW = new JLabel(),
                            lblDataRW_JumlahRW = new JLabel(),
                            
                            lblDP_Nik = new JLabel(),
                            lblDP_Nama = new JLabel(),
                            lblDP_TempatLahir = new JLabel(),
                            lblDP_TanggalLahir = new JLabel(),
                            lblDP_JenisKelamin = new JLabel(),
                            lblDP_Agama = new JLabel(),
                            lblDP_Alamat = new JLabel(),
                            lblDP_Status = new JLabel(),
                            lblDP_Pekerjaan = new JLabel(),
                            lblDP_Kewarganegaraan = new JLabel(),
                            lblDP_RT = new JLabel(),
                            lblDP_RW = new JLabel(),
                            
                            lblDPT_IdPetugas = new JLabel(),
                            lblDPT_Nama = new JLabel(),
                            lblDPT_Alamat = new JLabel(),
                            lblDPT_JenisKelamin = new JLabel(),
                            lblDPT_Password = new JLabel(),
                            lblDPT_NoTelepon = new JLabel();
    
    private static JTextField   txfdRT_KodeRT = new JTextField(),
                                txfdRT_NamaRT = new JTextField(),
                                txfdRT_JumlahRT = new JTextField(),
                                
                                txfdRW_KodeRW = new JTextField(),
                                txfdRW_NamaRW = new JTextField(),
                                txfdRW_JumlahRW = new JTextField(),
                                
                                txfdDP_Nik = new JTextField(),
                                txfdDP_Nama = new JTextField(),
                                txfdDP_TmpLahir = new JTextField(),
                                txfdDP_TglLahir = new JTextField(),
                                txfdDP_JenisKelamin = new JTextField(),
                                txfdDP_Agama = new JTextField(),
                                txfdDP_Alamat = new JTextField(),
                                txfdDP_Status = new JTextField(),
                                txfdDP_Pekerjaan = new JTextField(),
                                txfdDP_Kewarganegaraan = new JTextField(),
                                txfdDP_RT = new JTextField(),
                                txfdDP_RW = new JTextField(),
                                
                                txfdDPT_IdPetugas = new JTextField(),
                                txfdDPT_Nama = new JTextField(),
                                txfdDPT_Alamat = new JTextField(),
                                txfdDPT_JenisKelamin = new JTextField(),
                                txfdDPT_Password = new JTextField(),
                                txfdDPT_NoTelepon = new JTextField();

    private static JButton      btnRT_Delete = new JButton(),
                                btnRT_Save = new JButton(),
                                btnRT_Cancel = new JButton(),
                                
                                btnRW_Delete = new JButton(),
                                btnRW_Save = new JButton(),
                                btnRW_Cancel = new JButton(),
                                
                                btnDP_Delete = new JButton(),
                                btnDP_Save = new JButton(),
                                btnDP_Cancel = new JButton(),
                                
                                btnDPT_Delete = new JButton(),
                                btnDPT_Save = new JButton(),
                                btnDPT_Cancel = new JButton();

    App() {
        super("Population Census");
        setSize(1200, 700);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        frmMDI.setLayout(null);
        this.add(frmMDI);

        MenuMaster.add(subMenuMDDataRT);
        MenuMaster.add(subMenuMDDataRW);
        MenuMaster.add(subMenuMDDetailPenduduk);
        MenuMaster.add(subMenuMDDataPetugas);
        MenuBar.add(MenuMaster);
        MenuBar.add(MenuExit);

        subMenuMDDataRT.addActionListener(new MenuHandler());
        subMenuMDDataRW.addActionListener(new MenuHandler());
        subMenuMDDetailPenduduk.addActionListener(new MenuHandler());
        subMenuMDDataPetugas.addActionListener(new MenuHandler());
        MenuExit.addActionListener(new MenuHandler());

        setContentPane(frmMDI);

        formDataRT = new JInternalFrame("Data RT");
        formDataRW = new JInternalFrame("Data RW"); 
        formDetailPenduduk = new JInternalFrame("Detail Penduduk");
        formDataPetugas = new JInternalFrame("Data Petugas");

        pnlDataRT = new JPanel();
        lblDataRT_KodeRT.setText("Kode RT");
        lblDataRT_KodeRT.setBounds(30, 20, 100, 25);
        pnlDataRT.add(lblDataRT_KodeRT);
        txfdRT_KodeRT.setBounds(140, 20, 230, 25);
        pnlDataRT.add(txfdRT_KodeRT);

        lblDataRT_NamaRT.setText("Nama Ketua RT");
        lblDataRT_NamaRT.setBounds(30, 50, 100, 25);
        pnlDataRT.add(lblDataRT_NamaRT);
        txfdRT_NamaRT.setBounds(140, 50, 230, 25);
        pnlDataRT.add(txfdRT_NamaRT);

        lblDataRT_JumlahRT.setText("Jumlah RT");
        lblDataRT_JumlahRT.setBounds(30, 80, 100, 25);
        pnlDataRT.add(lblDataRT_JumlahRT);
        txfdRT_JumlahRT.setBounds(140, 80, 230, 25);
        pnlDataRT.add(txfdRT_JumlahRT); 

        btnRT_Delete.setText("Delete");
        btnRT_Delete.setBounds(30, 110, 80, 25);
        pnlDataRT.add(btnRT_Delete); 
        btnRT_Save.setText("Save");
        btnRT_Save.setBounds(130, 110, 80, 25);
        pnlDataRT.add(btnRT_Save); 
        btnRT_Cancel.setText("Cancel");
        btnRT_Cancel.setBounds(230, 110, 80, 25);
        pnlDataRT.add(btnRT_Cancel); 

        btnRT_Delete.addActionListener(new btnHandlerRT());
        btnRT_Save.addActionListener(new btnHandlerRT());
        btnRT_Cancel.addActionListener(new btnHandlerRT());

        pnlDataRT.setLayout(null);
        formDataRT.add(pnlDataRT);

        pnlDataRW  = new JPanel();
        lblDataRW_KodeRW.setText("Kode RW");
        lblDataRW_KodeRW.setBounds(30, 20, 100, 25);
        pnlDataRW.add(lblDataRW_KodeRW);
        txfdRW_KodeRW.setBounds(140, 20, 220, 25);
        pnlDataRW.add(txfdRW_KodeRW);

        lblDataRW_NamaRW.setText("Nama Ketua RW");
        lblDataRW_NamaRW.setBounds(30, 50, 100, 25);
        pnlDataRW.add(lblDataRW_NamaRW);
        txfdRW_NamaRW.setBounds(140, 50, 220, 25);
        pnlDataRW.add(txfdRW_NamaRW);

        lblDataRW_JumlahRW.setText("Jumlah RW");
        lblDataRW_JumlahRW.setBounds(30, 80, 100, 25);
        pnlDataRW.add(lblDataRW_JumlahRW);
        txfdRW_JumlahRW.setBounds(140, 80, 220, 25);
        pnlDataRW.add(txfdRW_JumlahRW); 

        btnRW_Delete.setText("Delete");
        btnRW_Delete.setBounds(30, 110, 80, 25);
        pnlDataRW.add(btnRW_Delete); 
        btnRW_Save.setText("Save");
        btnRW_Save.setBounds(130, 110, 80, 25);
        pnlDataRW.add(btnRW_Save); 
        btnRW_Cancel.setText("Cancel");
        btnRW_Cancel.setBounds(230, 110, 80, 25);
        pnlDataRW.add(btnRW_Cancel); 

        btnRW_Delete.addActionListener(new btnHandlerRW());
        btnRW_Save.addActionListener(new btnHandlerRW());
        btnRW_Cancel.addActionListener(new btnHandlerRW());

        pnlDataRW.setLayout(null);
        formDataRW.add(pnlDataRW);

        pnlDetailPenduduk = new JPanel();
        lblDP_Nik.setText("NIK");
        lblDP_Nik.setBounds(30, 20, 100, 25);
        pnlDetailPenduduk.add(lblDP_Nik);
        txfdDP_Nik.setBounds(140, 20, 220, 25);
        pnlDetailPenduduk.add(txfdDP_Nik);

        lblDP_Nama.setText("Nama");
        lblDP_Nama.setBounds(30, 50, 100, 25);
        pnlDetailPenduduk.add(lblDP_Nama);
        txfdDP_Nama.setBounds(140, 50, 220, 25);
        pnlDetailPenduduk.add(txfdDP_Nama);

        lblDP_TempatLahir.setText("Tempat Lahir");
        lblDP_TempatLahir.setBounds(30, 80, 100, 25);
        pnlDetailPenduduk.add(lblDP_TempatLahir);
        txfdDP_TmpLahir.setBounds(140, 80, 220, 25);
        pnlDetailPenduduk.add(txfdDP_TmpLahir);

        lblDP_TanggalLahir.setText("Tanggal Lahir");
        lblDP_TanggalLahir.setBounds(30, 110, 100, 25);
        pnlDetailPenduduk.add(lblDP_TanggalLahir);
        txfdDP_TglLahir.setBounds(140, 110, 220, 25);
        pnlDetailPenduduk.add(txfdDP_TglLahir);

        lblDP_JenisKelamin.setText("Jenis Kelamin");
        lblDP_JenisKelamin.setBounds(30, 140, 100, 25);
        pnlDetailPenduduk.add(lblDP_JenisKelamin);
        txfdDP_JenisKelamin.setBounds(140, 140, 220, 25);
        pnlDetailPenduduk.add(txfdDP_JenisKelamin);

        lblDP_Agama.setText("Agama");
        lblDP_Agama.setBounds(30, 170, 100, 25);
        pnlDetailPenduduk.add(lblDP_Agama);
        txfdDP_Agama.setBounds(140, 170, 220, 25);
        pnlDetailPenduduk.add(txfdDP_Agama);

        lblDP_Alamat.setText("Alamat");
        lblDP_Alamat.setBounds(30, 200, 100, 25);
        pnlDetailPenduduk.add(lblDP_Alamat);
        txfdDP_Alamat.setBounds(140, 200, 220, 25);
        pnlDetailPenduduk.add(txfdDP_Alamat);

        lblDP_Status.setText("Status");
        lblDP_Status.setBounds(30, 230, 100, 25);
        pnlDetailPenduduk.add(lblDP_Status);
        txfdDP_Status.setBounds(140, 230, 220, 25);
        pnlDetailPenduduk.add(txfdDP_Status);

        lblDP_Pekerjaan.setText("Pekerjaan");
        lblDP_Pekerjaan.setBounds(30, 260, 100, 25);
        pnlDetailPenduduk.add(lblDP_Pekerjaan);
        txfdDP_Pekerjaan.setBounds(140, 260, 220, 25);
        pnlDetailPenduduk.add(txfdDP_Pekerjaan);

        lblDP_Kewarganegaraan.setText("Kewarganegaraan");
        lblDP_Kewarganegaraan.setBounds(30, 290, 100, 25);
        pnlDetailPenduduk.add(lblDP_Kewarganegaraan);
        txfdDP_Kewarganegaraan.setBounds(140, 290, 220, 25);
        pnlDetailPenduduk.add(txfdDP_Kewarganegaraan);

        lblDP_RT.setText("RT");
        lblDP_RT.setBounds(30, 320, 100, 25);
        pnlDetailPenduduk.add(lblDP_RT);
        txfdDP_RT.setBounds(140, 320, 220, 25);
        pnlDetailPenduduk.add(txfdDP_RT);

        lblDP_RW.setText("RW");
        lblDP_RW.setBounds(30, 350, 100, 25);
        pnlDetailPenduduk.add(lblDP_RW);
        txfdDP_RW.setBounds(140, 350, 220, 25);
        pnlDetailPenduduk.add(txfdDP_RW);

        btnDP_Delete.setText("Delete");
        btnDP_Delete.setBounds(30, 380, 80, 25);
        pnlDetailPenduduk.add(btnDP_Delete); 
        btnDP_Save.setText("Save");
        btnDP_Save.setBounds(130, 380, 80, 25);
        pnlDetailPenduduk.add(btnDP_Save); 
        btnDP_Cancel.setText("Cancel");
        btnDP_Cancel.setBounds(230, 380, 80, 25);
        pnlDetailPenduduk.add(btnDP_Cancel); 

        btnDP_Delete.addActionListener(new btnHandlerDP());
        btnDP_Save.addActionListener(new btnHandlerDP());
        btnDP_Cancel.addActionListener(new btnHandlerDP());

        pnlDetailPenduduk.setLayout(null);
        formDetailPenduduk.add(pnlDetailPenduduk);

        pnlDetailPetugas = new JPanel();
        lblDPT_IdPetugas.setText("ID Petugas");
        lblDPT_IdPetugas.setBounds(30, 20, 100, 25);
        pnlDetailPetugas.add(lblDPT_IdPetugas);
        txfdDPT_IdPetugas.setBounds(140, 20, 220, 25);
        pnlDetailPetugas.add(txfdDPT_IdPetugas);

        lblDPT_Nama.setText("Nama Petugas");
        lblDPT_Nama.setBounds(30, 50, 100, 25);
        pnlDetailPetugas.add(lblDPT_Nama);
        txfdDPT_Nama.setBounds(140, 50, 220, 25);
        pnlDetailPetugas.add(txfdDPT_Nama);

        lblDPT_Alamat.setText("Alamat");
        lblDPT_Alamat.setBounds(30, 80, 100, 25);
        pnlDetailPetugas.add(lblDPT_Alamat);
        txfdDPT_Alamat.setBounds(140, 80, 220, 25);
        pnlDetailPetugas.add(txfdDPT_Alamat);

        lblDPT_JenisKelamin.setText("Jenis Kelamin");
        lblDPT_JenisKelamin.setBounds(30, 110, 100, 25);
        pnlDetailPetugas.add(lblDPT_JenisKelamin);
        txfdDPT_JenisKelamin.setBounds(140, 110, 220, 25);
        pnlDetailPetugas.add(txfdDPT_JenisKelamin);

        lblDPT_Password.setText("Password");
        lblDPT_Password.setBounds(30, 140, 100, 25);
        pnlDetailPetugas.add(lblDPT_Password);
        txfdDPT_Password.setBounds(140, 140, 220, 25);
        pnlDetailPetugas.add(txfdDPT_Password);

        lblDPT_NoTelepon.setText("No Telepon");
        lblDPT_NoTelepon.setBounds(30, 170, 100, 25);
        pnlDetailPetugas.add(lblDPT_NoTelepon);
        txfdDPT_NoTelepon.setBounds(140, 170, 220, 25);
        pnlDetailPetugas.add(txfdDPT_NoTelepon);

        btnDPT_Delete.setText("Delete");
        btnDPT_Delete.setBounds(30, 200, 80, 25);
        pnlDetailPetugas.add(btnDPT_Delete); 
        btnDPT_Save.setText("Save");
        btnDPT_Save.setBounds(130, 200, 80, 25);
        pnlDetailPetugas.add(btnDPT_Save); 
        btnDPT_Cancel.setText("Cancel");
        btnDPT_Cancel.setBounds(230, 200, 80, 25);
        pnlDetailPetugas.add(btnDPT_Cancel);

        btnDPT_Delete.addActionListener(new btnHandlerDPT());
        btnDPT_Save.addActionListener(new btnHandlerDPT());
        btnDPT_Cancel.addActionListener(new btnHandlerDPT());

        pnlDetailPetugas.setLayout(null);
        formDataPetugas.add(pnlDetailPetugas);

        frmMDI.add(formDataRT);
        frmMDI.add(formDataRW);
        frmMDI.add(formDetailPenduduk);
        frmMDI.add(formDataPetugas);

        formDataRT.setBounds(10, 10, 400, 250);
        formDataRW.setBounds(30, 30, 400, 250);
        formDetailPenduduk.setBounds(50, 50, 400, 530);
        formDataPetugas.setBounds(70, 70, 400, 340);

        setJMenuBar(MenuBar);
        setVisible(true); 


    }

    private static void runRTLoad() {
        boolean QuerySukses = false;
        System.out.println("Load Data RT");
        try {
            if (conn != null) {

                String q1 = "SELECT kode_rt, nama_rt, jumlah_rt FROM `" + StringTabelRT + "` LIMIT 1";
                Statement st = conn.createStatement();
                ResultSet rs = st.executeQuery(q1);

                while (rs.next()) {
                    txfdRT_KodeRT.setText(rs.getString("kode_rt"));
                    txfdRT_NamaRT.setText(rs.getString("nama_rt"));
                    txfdRT_JumlahRT.setText(rs.getString("jumlah_rt"));
                }

                st.close();
                QuerySukses = true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        if (QuerySukses) {
            System.out.println("Success Load Data RT");
        }
    }

    private static void runRTSave() {
        boolean QuerySukses = false;
        System.out.println("Save Data RT");
        try {
            if (conn != null) {
                ArrayList<String> queries = new ArrayList<String>();
                String q1 = "DELETE FROM  `" + StringTabelRT + "`"; 
                queries.add(q1);
                String q2 = "INSERT INTO `" + StringTabelRT + "` (`id`, `kode_rt`, `nama_rt`, `jumlah_rt`) VALUES (NULL, '" + txfdRT_KodeRT.getText() + "', '" + txfdRT_NamaRT.getText() + "', '" + txfdRT_JumlahRT.getText() + "')";
                queries.add(q2);

                Statement st = conn.createStatement();
                for (String query : queries) {
                    st.addBatch(query);
                }
                st.executeBatch();

                st.close();
                QuerySukses = true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        if (QuerySukses) {
            System.out.println("Success Save Data RT");
        }
    }

    private static void runRTDelete() {
        boolean QuerySukses = false;
        System.out.println("Delete Data RT");
        try {
            if (conn != null) {
                ArrayList<String> queries = new ArrayList<String>();
                String q1 = "DELETE FROM  `" + StringTabelRT + "`";
                queries.add(q1);

                Statement st = conn.createStatement();
                for (String query : queries) {
                    st.addBatch(query);
                }
                st.executeBatch();

                st.close();
                QuerySukses = true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        if (QuerySukses) {
            System.out.println("Success Delete Data RT");
        }
    }

    private static void runRWLoad() {
        boolean QuerySukses = false;
        System.out.println("Load Data RW");
        try {
            if (conn != null) {

                String q1 = "SELECT kode_rw, nama_rw, jumlah_rw FROM `" + StringTabelRW + "` LIMIT 1";
                Statement st = conn.createStatement();
                ResultSet rs = st.executeQuery(q1);

                while (rs.next()) {
                    txfdRW_KodeRW.setText(rs.getString("kode_rw"));
                    txfdRW_NamaRW.setText(rs.getString("nama_rw"));
                    txfdRW_JumlahRW.setText(rs.getString("jumlah_rw"));
                }

                st.close();
                QuerySukses = true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        if (QuerySukses) {
            System.out.println("Success Load Data RW");
        }
    }

    private static void runRWSave() {
        boolean QuerySukses = false;
        System.out.println("Save Data RW");
        try {
            if (conn != null) {
                ArrayList<String> queries = new ArrayList<String>();
                String q1 = "DELETE FROM  `" + StringTabelRW + "`"; 
                queries.add(q1);
                String q2 = "INSERT INTO `" + StringTabelRW + "` (`id`, `kode_rw`, `nama_rw`, `jumlah_rw`) VALUES (NULL, '" + txfdRW_KodeRW.getText() + "', '" + txfdRW_NamaRW.getText() + "', '" + txfdRW_JumlahRW.getText() + "')";
                queries.add(q2);

                Statement st = conn.createStatement();
                for (String query : queries) {
                    st.addBatch(query);
                }
                st.executeBatch();

                st.close();
                QuerySukses = true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        if (QuerySukses) {
            System.out.println("Success Save Data RW");
        }
    }

    private static void runRWDelete() {
        boolean QuerySukses = false;
        System.out.println("Delete Data RW");
        try {
            if (conn != null) {
                ArrayList<String> queries = new ArrayList<String>();
                String q1 = "DELETE FROM  `" + StringTabelRW + "`";
                queries.add(q1);

                Statement st = conn.createStatement();
                for (String query : queries) {
                    st.addBatch(query);
                }
                st.executeBatch();

                st.close();
                QuerySukses = true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        if (QuerySukses) {
            System.out.println("Success Delete Data RW");
        }
    }

    private static void runDPLoad() {
        boolean QuerySukses = false;
        System.out.println("Load Data Penduduk");
        try {
            if (conn != null) {

                String q1 = "SELECT nik_penduduk, nama_penduduk, tmp_lahir_penduduk, tgl_lahir_penduduk, jenis_kelamin_penduduk, agama_penduduk, alamat_penduduk, status_penduduk, pekerjaan_penduduk, kewarganegaraan_penduduk, rt_penduduk, rw_penduduk FROM `" + StringTabelDP + "` LIMIT 1";
                Statement st = conn.createStatement();
                ResultSet rs = st.executeQuery(q1);

                while (rs.next()) {
                    txfdDP_Nik.setText(rs.getString("nik_penduduk"));
                    txfdDP_Nama.setText(rs.getString("nama_penduduk"));
                    txfdDP_TmpLahir.setText(rs.getString("tmp_lahir_penduduk"));
                    txfdDP_TglLahir.setText(rs.getString("tgl_lahir_penduduk"));
                    txfdDP_JenisKelamin.setText(rs.getString("jenis_kelamin_penduduk"));
                    txfdDP_Agama.setText(rs.getString("agama_penduduk"));
                    txfdDP_Alamat.setText(rs.getString("alamat_penduduk"));
                    txfdDP_Status.setText(rs.getString("status_penduduk"));
                    txfdDP_Pekerjaan.setText(rs.getString("pekerjaan_penduduk"));
                    txfdDP_Kewarganegaraan.setText(rs.getString("kewarganegaraan_penduduk"));
                    txfdDP_RT.setText(rs.getString("rt_penduduk"));
                    txfdDP_RW.setText(rs.getString("rw_penduduk"));
                }

                st.close();
                QuerySukses = true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        if (QuerySukses) {
            System.out.println("Success Load Data Penduduk");
        }
    }

    private static void runDPSave() {
        boolean QuerySukses = false;
        System.out.println("Save Data Penduduk");
        try {
            if (conn != null) {
                ArrayList<String> queries = new ArrayList<String>();
                String q1 = "DELETE FROM  `" + StringTabelDP + "`"; 
                queries.add(q1);

                String q2 = "INSERT INTO `" + StringTabelDP + "` (`id`, `nik_penduduk`, `nama_penduduk`, `tmp_lahir_penduduk`, `tgl_lahir_penduduk`, `jenis_kelamin_penduduk`, `agama_penduduk`, `alamat_penduduk`, `status_penduduk`, `pekerjaan_penduduk`, `kewarganegaraan_penduduk`, `rt_penduduk`, `rw_penduduk`) VALUES (NULL, '" + txfdDP_Nik.getText() + "', '" + txfdDP_Nama.getText() + "', '" + txfdDP_TmpLahir.getText() + "', '" + txfdDP_TglLahir.getText() + "', '" + txfdDP_JenisKelamin.getText() + "', '" + txfdDP_Agama.getText() + "', '" + txfdDP_Alamat.getText() + "', '" + txfdDP_Status.getText() + "', '" + txfdDP_Pekerjaan.getText() + "', '" + txfdDP_Kewarganegaraan.getText() + "', '" + txfdDP_RT.getText() + "', '" + txfdDP_RW.getText() + "')";
                queries.add(q2);

                Statement st = conn.createStatement();
                for (String query : queries) {
                    st.addBatch(query);
                }
                st.executeBatch();

                st.close();
                QuerySukses = true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        if (QuerySukses) {
            System.out.println("Success Save Data Penduduk");
        }
    }

    private static void runDPDelete() {
        boolean QuerySukses = false;
        System.out.println("Delete Data Penduduk");
        try {
            if (conn != null) {
                ArrayList<String> queries = new ArrayList<String>();
                String q1 = "DELETE FROM  `" + StringTabelDP + "`";
                queries.add(q1);

                Statement st = conn.createStatement();
                for (String query : queries) {
                    st.addBatch(query);
                }
                st.executeBatch();

                st.close();
                QuerySukses = true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        if (QuerySukses) {
            System.out.println("Success Delete Data Penduduk");
        }
    }

    private static void runDPTLoad() {
        boolean QuerySukses = false;
        System.out.println("Load Data Petugas");
        try {
            if (conn != null) {

                String q1 = "SELECT id_petugas, nama_petugas, alamat_petugas, jenis_kelamin, password_petugas, telepon_petugas FROM `" + StringTabelDPT + "` LIMIT 1";
                Statement st = conn.createStatement();
                ResultSet rs = st.executeQuery(q1);

                while (rs.next()) {
                    txfdDPT_IdPetugas.setText(rs.getString("id_petugas"));
                    txfdDPT_Nama.setText(rs.getString("nama_petugas"));
                    txfdDPT_Alamat.setText(rs.getString("alamat_petugas"));
                    txfdDPT_JenisKelamin.setText(rs.getString("jenis_kelamin"));
                    txfdDPT_Password.setText(rs.getString("password_petugas"));
                    txfdDPT_NoTelepon.setText(rs.getString("telepon_petugas"));
                }

                st.close();
                QuerySukses = true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        if (QuerySukses) {
            System.out.println("Success Load Data Petugas");
        }
    }

    private static void runDPTSave() {
        boolean QuerySukses = false;
        System.out.println("Save Data Petugas");
        try {
            if (conn != null) {
                ArrayList<String> queries = new ArrayList<String>();
                String q1 = "DELETE FROM  `" + StringTabelDPT + "`"; 
                queries.add(q1);

                String q2 = "INSERT INTO `" + StringTabelDPT + "` (`id`, `id_petugas`, `nama_petugas`, `alamat_petugas`, `jenis_kelamin`, `password_petugas`, `telepon_petugas`) VALUES (NULL, '" + txfdDPT_IdPetugas.getText() + "', '" + txfdDPT_Nama.getText() + "', '" + txfdDPT_Alamat.getText() + "', '" + txfdDPT_JenisKelamin.getText() + "', '" + txfdDPT_Password.getText() + "', '" + txfdDPT_NoTelepon.getText() + "')";
                queries.add(q2);

                Statement st = conn.createStatement();
                for (String query : queries) {
                    st.addBatch(query);
                }
                st.executeBatch();

                st.close();
                QuerySukses = true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        if (QuerySukses) {
            System.out.println("Success Save Data Petugas");
        }
    }

    private static void runDPTDelete() {
        boolean QuerySukses = false;
        System.out.println("Delete Data Petugas");
        try {
            if (conn != null) {
                ArrayList<String> queries = new ArrayList<String>();
                String q1 = "DELETE FROM  `" + StringTabelDPT + "`";
                queries.add(q1);

                Statement st = conn.createStatement();
                for (String query : queries) {
                    st.addBatch(query);
                }
                st.executeBatch();

                st.close();
                QuerySukses = true;
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        if (QuerySukses) {
            System.out.println("Success Delete Data Petugas");
        }
    }

    private class MenuHandler implements ActionListener {
        public void actionPerformed(ActionEvent e){
            JMenuItem M = (JMenuItem)e.getSource();
        
            if (M.getText().equals("Data RT")) {
                formDataRT.setVisible(true);
                runRTLoad();
            } else if (M.getText().equals("Data RW")) {
                formDataRW.setVisible(true);
                runRWLoad();
            } else if (M.getText().equals("Detail Penduduk")) {
                formDetailPenduduk.setVisible(true);
                runDPLoad();
            } else if (M.getText().equals("Data Petugas")) {
                formDataPetugas.setVisible(true);
                runDPTLoad();
            } else if (M.getText().equals("Exit")) {
                DatabaseClose();
                dispose();
            }
        }
    }
    
    private class btnHandlerRT implements ActionListener {
        public void actionPerformed(ActionEvent e){
            JButton TblPilih = (JButton)e.getSource();

            if (TblPilih.getText().equals("Save")) {
                JOptionPane.showMessageDialog(frmMDI, "Data Save");
                runRTSave();
            } else if (TblPilih.getText().equals("Delete")) {
                runRTDelete();
                txfdRT_KodeRT.setText("");
                txfdRT_NamaRT.setText("");
                txfdRT_JumlahRT.setText("");
            }  else if (TblPilih.getText().equals("Cancel")) {
                formDataRT.setVisible(false);
            } 
        }
    }

    private class btnHandlerRW implements ActionListener {
        public void actionPerformed(ActionEvent e){
            JButton TblPilih = (JButton)e.getSource();

            if (TblPilih.getText().equals("Save")) {
                JOptionPane.showMessageDialog(frmMDI, "Data Save");
                runRWSave();
            } else if (TblPilih.getText().equals("Delete")) {
                runRWDelete();
                txfdRW_KodeRW.setText("");
                txfdRW_NamaRW.setText("");
                txfdRW_JumlahRW.setText("");
            }  else if (TblPilih.getText().equals("Cancel")) {
                formDataRW.setVisible(false);
            } 
        }
    }

    private class btnHandlerDP implements ActionListener {
        public void actionPerformed(ActionEvent e){
            JButton TblPilih = (JButton)e.getSource();

            if (TblPilih.getText().equals("Save")) {
                JOptionPane.showMessageDialog(frmMDI, "Data Save");
                runDPSave();
            } else if (TblPilih.getText().equals("Delete")) {
                runDPDelete();
                txfdDP_Nik.setText("");
                txfdDP_Nama.setText("");
                txfdDP_TmpLahir.setText("");
                txfdDP_TglLahir.setText("");
                txfdDP_JenisKelamin.setText("");
                txfdDP_Agama.setText("");
                txfdDP_Alamat.setText("");
                txfdDP_Status.setText("");
                txfdDP_Pekerjaan.setText("");
                txfdDP_Kewarganegaraan.setText("");
                txfdDP_RT.setText("");
                txfdDP_RW.setText("");
            }  else if (TblPilih.getText().equals("Cancel")) {
                formDetailPenduduk.setVisible(false);
            } 
        }
    }

    private class btnHandlerDPT implements ActionListener {
        public void actionPerformed(ActionEvent e){
            JButton TblPilih = (JButton)e.getSource();

            if (TblPilih.getText().equals("Save")) {
                JOptionPane.showMessageDialog(frmMDI, "Data Save");
                runDPTSave();
            } else if (TblPilih.getText().equals("Delete")) {
                runDPTDelete();
                txfdDPT_IdPetugas.setText("");
                txfdDPT_Nama.setText("");
                txfdDPT_Alamat.setText("");
                txfdDPT_JenisKelamin.setText("");
                txfdDPT_Password.setText("");
                txfdDPT_NoTelepon.setText("");
            }  else if (TblPilih.getText().equals("Cancel")) {
                formDataPetugas.setVisible(false);
            } 
        }
    }

    private static void DatabaseDriver() {
        try {
            System.out.println("Set Driver");
            Class.forName(StringDriver);
        } catch (ClassNotFoundException ex) {
            System.out.println("Driver " + StringDriver + " Tidak Ditemukan");
        }
    }

    private static void DatabaseKoneksi() {
        boolean KoneksiAman = false;
        DatabaseDriver();

        try {
            System.out.println("Menghubungkan Koneksi Ke Database");
            conn = DriverManager.getConnection(StringConnection, StringConnectionUser, StringConnectionPass);
            KoneksiAman = true;
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }

        if (KoneksiAman) {
            System.out.println("Terhubung ke Database");
        }
    }

    private static void DatabaseClose() {
        try {
            if (conn != null)
                conn.close();
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }

        conn = null;
    }

    public static void main(String[] args) throws Exception {
        new App();

        DatabaseKoneksi();
    }
}
