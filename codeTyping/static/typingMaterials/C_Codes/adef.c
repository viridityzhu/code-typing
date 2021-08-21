main() {
    int x, m;
    scanf("%d", & x);
    m = sub(x);
    printf("m=%d\n", m);
}
int sub(x)
int x; {
    int a, b, c, n;
    a = 6;
    b = 30;
    c = 15;
    if (x <= a)
        n = b * x + a * a;
    else
        n = a * (c - x) + c * c;
    return (n);
}