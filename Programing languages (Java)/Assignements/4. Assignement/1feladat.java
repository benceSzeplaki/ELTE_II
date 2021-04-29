class Foo {
    private int x;

    public Foo(int x) {
        this.x = x;
    }
}

class Main {
    public static void main(String[] args) {
        Foo obj = new Foo(0);
        obj = new Foo(10);
        Foo obj2 = obj;
        int i = 1;
        obj2 = new Foo(20);
    }
}