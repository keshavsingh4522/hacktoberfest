import java.util.ArrayList;

final class CorrectNonogram {

    boolean correctNonogram(int size, String[][] nonogramField) {
        int len = (size + 1) / 2, sz = len + size, c = 0;
        ArrayList<String> row = new ArrayList();
        ArrayList<String> col = new ArrayList();
        for(int x = (size + 1) / 2; x < sz; x++) {
            String val = "", reg = "";
            for(int y = 0; y < sz; y++) {
                row.add(nonogramField[x][y]);
                col.add(nonogramField[y][x]);
            }
            for(int i = len; i < sz; i++) { val += row.get(i); }
            int d = 0;
            for(int i = 0; i < len; i++) {
                if(d == 0) {
                    if(row.get(i).matches("\\d+")) {
                        reg += "#{"+row.get(i)+"}";
                        d++;
                    }
                }
                else {
                    if(row.get(i).matches("\\d+")) {
                        reg += ".+#{"+row.get(i)+"}";
                    }
                }
            }
            if(!val.matches("\\.*"+reg+"\\.*")) { c++; }
            reg = val = "";
            d = 0;
            for(int i = len; i < sz; i++) { val += col.get(i); }
            for(int i = 0; i < len; i++) {
                if(d == 0) {
                    if(col.get(i).matches("\\d+")) {
                        reg += "#{"+col.get(i)+"}";
                        d++;
                    }
                }
                else {
                    if(col.get(i).matches("\\d+")) {
                        reg += ".+#{"+col.get(i)+"}";
                    }
                }
            }
            if(!val.matches("\\.*"+reg+"\\.*")) { c++; }
            col.clear();
            row.clear();
        }
        return c == 0;
    }
}