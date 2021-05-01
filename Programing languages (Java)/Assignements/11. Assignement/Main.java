import list.*;

public class Main 
{
    public static void main(String[] args) 
    {
        //------------------------------------------------------------------------------------------------------------------------------
        //(a)
        //Cheking IntList(with satisfactory initializer):
        IntList list = new IntList(4);
        if(list.getCurrentSize() == 0 && list.getMaxSize() == 4)
        {
            System.out.println("IntList: Constructor is working properly with satisfactory initializer.");
        }

        //Cheking IntList(with non-satisfactory initializer):
        try { IntList list2 = new IntList(-1); }
        catch(IllegalArgumentException e)
        {
            e.printStackTrace();
            System.out.println("IntList: Constructor is working with non-satisfactory initializer.");
        }

        //Checking IntList.toString() on empty list:
        if(list.toString().equals("empty"))
        {
            System.out.println("IntList.toString() is working on empty lists.");
        }

        //Adding elements to IntList till we reach the maxSize of the list:
        for(int i = 0; i < list.getMaxSize() ; i++)
        {
            list.add(i);
        }

        //Checking IntList.toString() on non-empty list:
        if(list.toString().equals("[ 0, 1, 2, 3 ]"))
        {
            System.out.println("IntList.toString() is working on non-empty lists.");
        }

        //Checking if IntList.add(int newInt) throws IllegalStateException:
        try
        {
            list.add(4);
        }
        catch(IllegalStateException e)
        {
            e.printStackTrace();
            System.out.println("IntList.add() method throws IllegalStateException if it cannot add more items to lists");
        }

        //Checking IntList.concat(IntList newList) with two lists that can be concatenated:
        IntList A = new IntList(6);
        IntList B = new IntList(3);
        A.add(1);
        A.add(2);
        A.add(3);
        B.add(4);
        B.add(5);
        B.add(6);
        A.concat(B);
        if(A.toString().equals("[ 1, 2, 3, 4, 5, 6 ]"))
        {
            System.out.println("IntList.concat() is working with two satisfactory list.");
        }

        //Checking IntList.concat(IntList newList) with two lists that can not be concatenated
        IntList C = new IntList(2);
        IntList D = new IntList(1);
        C.add(1);
        C.add(2);
        D.add(3);
        try
        {
            C.concat(D);
        }
        catch(IllegalStateException e)
        {
            e.printStackTrace();
            System.out.println("IntList.concat() method throws IllegalStateException if it cannot concatenate two lists.");
        }

        //IntList A = [ 1, 2, 3, 4, 5, 6 ]
        //Checking IntList.removeItemsGreaterThan(int limit):
        A.removeItemsGreaterThan(4);
        if(A.getCurrentSize() == 4 && A.toString().equals("[ 1, 2, 3, 4 ]"))
        {
            System.out.println("IntList.removeItemsGreaterThan(int limit) method is working.");
        }

        //-------------------------------------------------------------------------------------------------------------------------------
        //(b)
        //Cheking IntList(with satisfactory initializer):
        IntArrayList arrayList = new IntArrayList(4);
        if(arrayList.getMaxSize() == 4)
        {
            System.out.println("IntArrayList: Constructor is working properly with satisfactory initializer.");
        }

        //Cheking IntList(with non-satisfactory initializer):
        try { IntArrayList arrayList2 = new IntArrayList(-1); }
        catch(IllegalArgumentException e)
        {
            e.printStackTrace();
            System.out.println("IntArrayList: Constructor is working with non-satisfactory initializer.");
        }

        //Checking IntList.toString() on empty list:
        /*System.out.println(arrayList.toString());
        if(arrayList.toString().equals("empty"))
        {
            System.out.println("IntArrayList.toString() is working on empty lists.");
        }*/

        //Adding elements to IntList till we reach the maxSize of the list:
        for(int i = 0; i < arrayList.getMaxSize() ; i++)
        {
            arrayList.add(i);
        }

        //Checking IntList.toString() on non-empty list:
        if(arrayList.toString().equals("[ 0, 1, 2, 3 ]"))
        {
            System.out.println("IntArrayList.toString() is working on non-empty lists.");
        }

        //Checking if IntList.add(int newInt) throws IllegalStateException:
        try
        {
            arrayList.add(4);
        }
        catch(IllegalStateException e)
        {
            e.printStackTrace();
            System.out.println("IntArrayList.add() method throws IllegalStateException if it cannot add more items to lists");
        }

        //Checking IntList.concat(IntList newList) with two lists that can be concatenated:
        IntArrayList E = new IntArrayList(6);
        IntArrayList F = new IntArrayList(3);
        E.add(1);
        E.add(2);
        E.add(3);
        F.add(4);
        F.add(5);
        F.add(6);
        E.concat(F);
        if(E.toString().equals("[ 1, 2, 3, 4, 5, 6 ]"))
        {
            System.out.println("IntArrayList.concat() is working with two satisfactory list.");
        }

        //Checking IntList.concat(IntList newList) with two lists that can not be concatenated
        IntArrayList G = new IntArrayList(2);
        IntArrayList H = new IntArrayList(1);
        G.add(1);
        G.add(2);
        H.add(3);
        try
        {
            G.concat(H);
        }
        catch(IllegalStateException e)
        {
            e.printStackTrace();
            System.out.println("IntArrayList.concat() method throws IllegalStateException if it cannot concatenate two lists.");
        }

        //IntList A = [ 1, 2, 3, 4, 5, 6 ]
        //Checking IntList.removeItemsGreaterThan(int limit):
        E.removeItemsGreaterThan(4);
        if(E.getSize() == 4 && E.toString().equals("[ 1, 2, 3, 4 ]"))
        {
            System.out.println("IntArrayList.removeItemsGreaterThan(int limit) method is working.");
        }

        //-------------------------------------------------------------------------------------------------------------------------------
        //(c)
        NamedIntArrayList namedList = new NamedIntArrayList("My first list ever made", 10);
        if(namedList.getMaxSize() == 10 && namedList.getName().equals("My first list ever made"))
        {
            System.out.println("NamedIntArrayList: Constructor(String, int) is working properly with satisfactory initializer.");
        }
        int[] arr = new int[5];
        for(int i = 0; i < arr.length; i++)
        {
            arr[i] = i + 1;
        }
        NamedIntArrayList namedList2 = new NamedIntArrayList("My second list", arr);
        if(namedList2.getMaxSize() == 5 && namedList2.getName().equals("My second list"))
        {
            System.out.println("NamedIntArrayList: Constructor(String, int[]) is working properly with satisfactory initializer.");
        }
        if(namedList2.toString().equals("Name of this list: My second list"+ System.lineSeparator() +"Contains: [1, 2, 3, 4, 5]"))
        {
            System.out.println("NamedIntArrayList.toString() is working properly.");
        }
    }    
}
