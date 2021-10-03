final class HigherVersion2 {

    int higherVersion2(String a, String b) {
        String[] r1 = a.split("\\.");
        String[] r2 = b.split("\\.");
        for(int i = 0; ; i++) {
            try {
                int t1 = new Integer(r1[i]), t2 = new Integer(r2[i]);
                if(t1 > t2) { return 1; }
                if(t1 < t2) { return -1; }
            }
            catch(Exception e) { return 0; }
        }
    }
}