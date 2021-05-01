//(a) feladat

package list;

public class IntList
{
    private int[] list;
    private int currentSize;
    private int maxSize;

    public IntList(int setMaxSize)
    {
        if(setMaxSize < 0) throw new IllegalArgumentException();
        maxSize = setMaxSize;
        list = new int[maxSize];
        currentSize = 0;
    }

    public IntList(int[] setIntList)
    {
        currentSize = 0;
        list = new int[setIntList.length];
        for(int i = 0; i < setIntList.length; i++)
        {
            list[i] = setIntList[i];
            currentSize++;
        }
        currentSize++;
        maxSize = currentSize;
    }

    public void add(int newInt)
    {
        if(currentSize < maxSize)
        {
            list[currentSize] = newInt;
            currentSize++;
        }
        else throw new IllegalStateException();
    }

    public int getCurrentSize()
    {
        return currentSize;
    }

    public int getElement(int i)
    {
        return list[i];
    }

    public int getMaxSize()
    {
        return maxSize;
    }

    public void concat(IntList newIntList)
    {
        int j = 0;
        if((currentSize + newIntList.getCurrentSize()) <= maxSize)
        {
            for(int i = currentSize; i < (currentSize + newIntList.getCurrentSize()); i++)
            {
                list[i] = newIntList.getElement(j);
                j++;
            }
            j = 0;
            currentSize = list.length;
        }
        else throw new IllegalStateException();
    }

    public String toString()
    {
        StringBuilder str = new StringBuilder();
        if(currentSize == 0)
        {
            str.append("empty");
        }
        else
        {
            str.append("[ ");
            for(int i = 0; i < list.length; i++)
            {
                if(i + 1 == list.length)
                {
                    str.append(list[i] +" ]");
                }
                else
                {
                    str.append(list[i] +", ");
                }
            }
        }
        return str.toString();
    }

    public void removeItem(int index)
    {
        if (list == null || index < 0 || index >= list.length) throw new IllegalArgumentException();
        int[] tmp = new int[list.length - 1];
        int j = 0;
        for(int i = 0; i < list.length; i++)
        {
            if(i == index)
            {
                continue;
            }
            else
            {
                tmp[j] = list[i];
                j++;
            }
        }
        list = tmp;
        currentSize = list.length + tmp.length;
    }

    public void removeItemsGreaterThan(int limit)
    {
        for(int i = 0; i < list.length; i++)
        {
            if(list[i] > limit)
            {
                removeItem(i);
            }
        }
    }

    public int[] getData()
    {
        return list;
    }
}