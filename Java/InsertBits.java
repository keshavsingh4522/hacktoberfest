public final class InsertBits {

    int insertBits(int n, int a, int b, int k) {
        String bn = new StringBuilder(Integer.toBinaryString(n))
                .reverse().toString(),
            bk = new StringBuilder(Integer.toBinaryString(k))
                .reverse().toString(),
            s = "";

        for(int i = 0, l = bn.length(); i < 31 - l; i++) bn += "0";
        for(int i = 0, l = bk.length(); i < 31 - l; i++) bk += "0";
        for(int x = 0, y = -1; x < bn.length(); x++) {
            if(x >= a && x <= b && y != bk.length() - 1) {
                y++;
                s += bk.charAt(y);
                continue;
            }
            s += bn.charAt(x);
        }

        return Integer.parseInt(new StringBuilder(s).reverse().toString(), 2);
    }
}