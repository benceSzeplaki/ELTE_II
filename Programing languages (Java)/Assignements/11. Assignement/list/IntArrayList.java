// (b) feladat: Észrevételeimet a kommentekben hagyom

package list;

import java.util.ArrayList;

public class IntArrayList 
{
    protected ArrayList<Integer> list;
    //private int currentSize; felesleges eltárolni a currentSize - ot, hiszen az ArrayList-nek van egy .size() metódusa, ami pontosan ezzel az értékkel tér vissza
    private int maxSize;

    public IntArrayList(int max)
    {
        if(max < 0) throw new IllegalArgumentException();
        this.list = new ArrayList<Integer>(max);
        maxSize = max;
    }

    public IntArrayList(int[] intArray)
    {
        this.list = new ArrayList<Integer>(intArray.length);
        for(int i = 0; i < intArray.length; i++)
        {
            list.add(intArray[i]);
        }
        maxSize = this.getSize();
    }

    public void add(int newInt)  // Ezt is sokkal egyszerűbb volt megírni, hiszen létezik .add() metódusa az ArrayList-nek
    {
        if(this.getSize() < maxSize)
        {
            this.list.add(newInt);
        }
        else throw new IllegalStateException();
    }

    public int getSize()
    {
        return list.size();
    }

    public int getMaxSize()
    {
        return maxSize;
    }

    public void concat(IntArrayList newIntArrayList) // Hmm... létezik .addAll() metódus, ami összefűz két ArrayList-et. WoW! ˇ-ˇ
    {
        if((this.getSize() + newIntArrayList.getSize()) <= maxSize)
        {
            list.addAll(newIntArrayList.list);
        }
        else throw new IllegalStateException();
    }

    public String toString() // Eeees igeeen! Van .toString-je is :D
    {
        return list.toString();
    }

    public void removeItemsGreaterThan(int limit) // Hát ehhez sem kellett írni egy külön removeItem-et, mert már volt .remove() és .get() :P
    {
        for(int i = 0; i < this.getSize(); i++)
        {
            if(list.get(i) > limit)
            {
                list.remove(i);
            }
        }
    }

    public int[] getData()
    {
        int[] ret = new int[this.getSize()];
        for(int i = 0; i < this.getSize(); i++)
        {
            ret[i] = list.get(i);
        }
        return ret;
    }
}