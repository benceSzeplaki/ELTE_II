class Complex 
{
	double re;
	double im;
	public Complex()
	{
		re = 0;
		im = 0;
	}
	double abs()
	{
		return Math.sqrt(Math.pow(re, 2) + Math.pow(im, 2));
	}
	Complex add(Complex c)
	{
		Complex h = new Complex();
		h.re = re + c.re;
		h.im = im + c.im;
		return h;
	}
	Complex sub(Complex c)
	{
		Complex h = new Complex();
		h.re = re - c.re;
		h.im = im - c.im;
		return h;
	}
	Complex mul(Complex c)
	{
		Complex h = new Complex();
		h.re = re * c.re - im * c.im;
		h.im = re * c.im + c.re * im;
		return h;
	}
	void printComplex()
	{
		if(im < 0)
		{
			System.out.print(re);
			System.out.println(im + "i");
		}
		else
		{
			System.out.println(re + "+" + im + "i");
		}
	}
	Complex conjugate()
	{
		Complex h = new Complex();
		h.re = re;
		h.im = im;
		h.im = h.im * (-1);
		return h;
	}
	double reciprocate()
	{
		double h;
		h = (re - im) / (Math.pow(re, 2) + Math.pow(im, 2));
		return h;
	}
	Complex div(Complex c)
	{
		Complex h = new Complex();
		h.re = (re * c.re + im * c.im) / (Math.pow(c.re, 2) - Math.pow(c.im, 2));
		h.im = (c.re * im - re * c.im) / (Math.pow(c.re, 2) - Math.pow(c.im, 2));
		return h;
	}
}
class ComplexMain
{
	public static void main(String[] args)
	{
		Complex alpha = new Complex();
		Complex beta = new Complex();
		alpha.re = 3;
		alpha.im = 2;
		beta.re = 1;
		beta.im = 2;
		System.out.print("Value of alpha: ");
		alpha.printComplex();
		System.out.print("Value of beta: ");
		beta.printComplex();
		System.out.print("Absolute value of alpha: ");
		System.out.println(alpha.abs());
		System.out.print("Sum of alpha and beta: ");
		alpha.add(beta).printComplex();
		System.out.print("Difference of alpha and beta: ");
		alpha.sub(beta).printComplex();
		System.out.print("Product of alpha and beta: ");
		alpha.mul(beta).printComplex();
		System.out.print("Quotient of alpha and beta: ");
		alpha.div(beta).printComplex();
		System.out.print("Conjugate of alpha: ");
		alpha.conjugate().printComplex();
		System.out.print("Reciprocal of alpha: ");
		System.out.println(alpha.reciprocate());
	}
}