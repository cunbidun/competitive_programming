package Code;

import Lib.Algorithm.MaxMin;

import java.util.Arrays;

@SuppressWarnings("unused")
public class CentipedeSocks {
    public int fewestSocks(int C, int F, int[] sockCounts) {
        int cnt = 0;
        for (int sockCount : sockCounts) {
            cnt += sockCount / F;
        }
        if (cnt < C) return -1;
        int ans = 0;
        for (int i = 0; i < sockCounts.length; i++) {
            System.out.print(sockCounts[i] + " ");
        }
        System.out.println();
        for (int i = 0; i < sockCounts.length; i++) {
            if (sockCounts[i] < F) {
                ans += sockCounts[i];
                sockCounts[i] = 0;
            } else if (sockCounts[i] >= F) {
                ans += F - 1;
                sockCounts[i] -= F - 1;
            }
        }
        Arrays.sort(sockCounts);

        while (C > 0) {
            for (int i = sockCounts.length - 1; i >= 0; i--) {
                if (sockCounts[i] >= 1) {
                    sockCounts[i]--;
                    ans++;
                    C--;
                    if (C == 0) break;
                    ans += MaxMin.Min(F - 1, sockCounts[i]);
                    sockCounts[i] = MaxMin.Max(0, sockCounts[i] - (F - 1));
                    break;

                }
            }
            Arrays.sort(sockCounts);
        }
        return ans;
    }
}
