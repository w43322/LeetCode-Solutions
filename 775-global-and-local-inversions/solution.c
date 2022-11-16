bool isIdealPermutation(const int *a, int n)
{
    int greatest = -1;
    for (int i = 2; i < n; ++i) {
        if (a[i - 2] > greatest) {
            greatest = a[i - 2];
        }
        if (a[i] < greatest) {
            return false;
        }
    }

    return true;
}
