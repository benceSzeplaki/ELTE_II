package game;

import game.utils.Vehicle;

public class Player
{
	String playerName;
	String ipAdress;
	int healthStatus;
	Vehicle v;

	String toStringPlayer()
	{
		String gamerInfo;
		if(v != null)
		{
			gamerInfo = "\n Name: " + playerName + "\n IP-Adress: " + ipAdress + "\n Health status: " + healthStatus + "\n License plate number: " + v.getPlateNumber();
		}
		else
		{
			gamerInfo = "\n Name: " + playerName + "\n IP-Adress: " + ipAdress + "\n Health status: " + healthStatus + "\n License plate number: " + playerName + " doesn't have a vehicle yet.";
		}
		return gamerInfo;
	}
}