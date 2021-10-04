public class LongestPalindrome {
    public static void main(String[] args){
        System.out.println(longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedi" +
                "catedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionoftha" +
                "tfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogeth" +
                "erfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannoth" +
                "allowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwe" +
                "rtoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhatt" +
                "heydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehav" +
                "ethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromth" +
                "esehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweher" +
                "ehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandth" +
                "atgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"));
    }

    public static int longestPalindrome(String s) {
        int[] charMap = new int[128];
        for(int i=0; i<s.length();i++)
            charMap[s.charAt(i) - 'A']++;
        int result =0, maxOdd =0;
        for(int i=0;i<128;i++)
            if(charMap[i] %2 ==0) result += charMap[i];
            else maxOdd = Math.max(maxOdd, charMap[i]);
        return result + maxOdd;
    }
}
