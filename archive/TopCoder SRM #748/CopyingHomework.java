package Code;

public class CopyingHomework {
    public int[] copy(int[] friendsHomework) {
        int[] ans = new int[5];
        for(int i = 0; i < friendsHomework.length - 1; i++) {
            ans[i] = friendsHomework[i] - 1;
        }
        ans[friendsHomework.length - 1] = friendsHomework[friendsHomework.length - 1] + 4;
        return ans;
    }
}
