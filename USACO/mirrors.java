import java.util.Scanner;
import java.io.*;
import java.util.ArrayList;

public class mirrors
{
static ArrayList <Integer> mirr = new ArrayList();
public static int go (int ind)
{
	int slash = 0;
	int dir = 0;
	if (mirr.get((ind*3)+2).intValue() == 1) slash = 2;
	else slash = 1;
	for (int k = 0; k < mirr.size(); k++)
	{
		
public static void main(String[] args)
{	
	try
	{
		Scanner input = new Scanner(new File("mirrors.in"));
		String firstLine = input.nextLine();
		final int N = Integer.parseInt(firstLine.split(" ")[0]);
		int a = Integer.parseInt(firstLine.split(" ")[1]);
		int b = Integer.parseInt(firstLine.split(" ")[2]);
		
		for (int i = 0; i < N; i++)
		{
			String line = input.nextLine();
			mirr.add(Integer.parseInt(line.split(" ")[0]));
			mirr.add(Integer.parseInt(line.split(" ")[1]));
			if (line.split(" ")[2].equals("/")) mirr.add(1);
			else mirr.add(2);
		}
		
		int val = 0;
		for (int j = 0; j < N; j++)
		{
			 