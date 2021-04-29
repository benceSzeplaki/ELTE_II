package game;

import game.utils.Vehicle;
import game.Player;

public class Main
{
	public static void main(String[] args) 
	{
		Vehicle car = new Vehicle();
		car.modelId = 1;
		car.setPlatenumber("ROL - 548");
		car.color1 = 1;
		car.color2 = 2;
		Vehicle motorbike = new Vehicle();
		motorbike.modelId = 2;
		motorbike.setPlatenumber("KFC - 412");
		motorbike.color1 = 3;
		motorbike.color2 = 5;
		Vehicle boat = new Vehicle();
		boat.modelId = 2;
		boat.setPlatenumber("KFC - 412");
		boat.color1 = 3;
		boat.color2 = 5;
		Player player1 = new Player();
		player1.playerName = "WildRider66";
		player1.ipAdress = "132.86.36.11";
		player1.healthStatus = 10;
		player1.v = null;
		Player player2 = new Player();
		player2.playerName = "Drifter365";
		player2.ipAdress = "132.86.36.11";
		player2.healthStatus = 8;
		player2.v = car;
        System.out.println(player1.toStringPlayer());
		System.out.println(player2.toStringPlayer());
	}
}
