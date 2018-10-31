/*
NAME: Trent Herdtner
EMAIL: therdtne@usc.edu
DESCRIPTION: This file includes constructor and destructor 
			for Web class, along with functions read_graph,
			write_graph, and calculate_rank.
*/

#include "web.h"

Web::Web()
{

}

Web::~Web()
{
	//pages.clear();
	walkers.clear();
	//map_walkers.clear();
}

//sets variables after taking input file
bool Web::read_graph(const char *filename)
{
	ifstream inputFile(filename); //use ifstream with filename

	if(inputFile.fail())
	{
		return false;
	}

	
	int num_pages;
	inputFile >> num_pages;

	
	if(inputFile.fail())
	{
		return false;
	}

	for(int i=0; i<num_pages; i++) //loops through pages
	{
		int id;
		string url;

		inputFile >> id >> url;

		if(inputFile.fail())
		{
			return false;
		}
		if(inputFile.fail())
		{
			return false;
		}

		Page newPage(id, url);

		double rank; // sets rank

		inputFile>>rank;

		if(inputFile.fail())
		{
			return false;
		}

		newPage.setRank(rank);

		string linkString; //sets links for each page

		inputFile.ignore();

		getline(inputFile, linkString);

		stringstream link_to_number(linkString);

		while(!link_to_number.eof())
		{
			int number;
			link_to_number >> number;

			if(link_to_number.fail())
			{
				break;
			}

			newPage.addLink(number); //add link to vector
		}

		pages.push_back(newPage); //adds to pages vector
	}

	return true;
}

bool Web::write_graph(const char *filename) // writes output file
{
	ofstream outputFile; 

	outputFile.open(filename);

	if(outputFile.fail())
	{
		return false;
	}

	outputFile << pages.size() << endl; // writes # pages


	for(int i=0; i<pages.size(); i++)//loops through pages
	{
		outputFile << pages[i].getID() << endl;//write page id

		outputFile << '\t' << pages[i].getURL() << endl;//write page url

		outputFile << '\t' << pages[i].getRank() << endl;//write pagerank

		outputFile << '\t';

		for (int j=0; j<pages[i].getLinks().size(); j++)//write link for each page, loops
		{
			outputFile << pages[i].getLinks()[j] << " ";

			
			//for last link written
			/*
			if(j == (pages[i].getLinks().size()-1) && j == 0)
			{
				outputFile << '\t' << pages[i].getLinks()[j] << 
				" " << endl;
			}
			else if(j==0)
			{
				outputFile << '\t' << pages[i].getLinks()[j] <<
				" " << endl;
			}
			else if(j==(pages[i].getLinks().size()-1))
			{
				outputFile << pages[i].getLinks()[j] << " " << endl;
			}
			else //for all the other links
			{
				outputFile << pages[i].getLinks()[j] << " " << endl;
			}*/
		}
		outputFile <<endl;
	}

	outputFile.close(); //close output file
	return true;
}

void Web::calculate_rank(int S, int N)//calculates pagerank using # simulations
										//and walkers.
{
	// int pageIndex = 0;

	// for(int i=0; i<N; i++)
	// {
	// 	map_walkers[i] = pageIndex;
	// 	pageIndex++;

	// 	if(pageIndex >= pages.size())
	// 	{
	// 		pageIndex = 0;
	// 	}
	// }

	// vector walkers
	// walkers[0] = 12; 

	// loop to initalize the size of vector walkers
	for(int i=0; i<pages.size(); i++)
	{
		walkers.push_back(0);
	}
	// loop to populate those pages with walkers as equally as possible
	for(int i=0; i<N; i++)
	{
		walkers[i%pages.size()] += 1; 
	}


	// start simulation 

	for(int i=0; i<S; i++)
	{
		vector<int> walkers_initial;
		for(int j = 0; j < walkers.size();j++)
		{
			walkers_initial.push_back(walkers[j]);
		}

		for(int k=0; k<pages.size(); k++)
		{
			for(int l = 0; l < walkers_initial[k];l++)
			{
				walkers[k] -=1;
				int random_index = rand() % pages[k].getLinks().size();
				int link_chosen = pages[k].getLinks()[random_index];
				walkers[link_chosen] += 1;
			}
		}
	}

	//start rank

	for(int i=0; i<pages.size(); i++)
	{
		double ratio = (double)walkers[i]/N;//holds ratio of walkers on page

		pages[i].setRank(ratio);//set rank for page to ratio
		
	}


	// create another vector identical to walkers which is going to be 
	// the initial number of walkers 

	// perform one cycle of the simulation and update walkers 

	// calculate rank via proportion 

	/*

	for(int i=0; i<S; i++)//simulation loop
	{
		for (int j=0; j < N; j++)//walkers loop
		{
			//random link index prom current page walker is on
			int rand_link_index = rand() % pages[walkers[j]].getLinks().size();
			//uses rand_link_index to get random link
			int rand_link = pages[walkers[j]].getLinks()[rand_link_index];
			//moves walker to random link
			walkers[j] = rand_link;
		}
	}

	for(int i=0; i<pages.size(); i++)//loops through # pages
	{ 
		int num_walkers = 0; // holds # walkers on page

		for(int j=0; j<N; j++)//loop through walkers
		{
			if(walkers[j] == i)//if walker is on page
			{
				num_walkers++;
			}

			double ratio = num_walkers/(double)N;//holds ratio of walkers on page

			pages[i].setRank(ratio);//set rank for page to ratio
		}
	}*/
}