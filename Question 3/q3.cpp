/**
 * @file q3.cpp
 * @author Paul Yong (2102088@sit.singaporetech.edu.sg)
 * @brief 
 * 		Implementation of Knuth-Morris-Pratt (KMP) Substring Search
 * 		using Deterministic Finite State Automata (DFA).
 * 
 * 		Looks for the occurence of pattern
 * 			ABABAC
 * 		in the text
 * 			BCBAABACAABABACAA
 * 
 * 		This program outputs the position if the pattern is found 
 * 		and terminates.
 * 
 * @version 0.1
 * @date 2022-11-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string> 	// std::string 
#include <iostream> // std::cout

#define NO_OF_CHARS 256 // ASCII is an 8-bit standard

/**
 * @brief Determines the next State based on the current state and character
 * 
 * @param pat 	Pattern
 * @param state Current State
 * @param c 	Input Character
 * @return int 
 */
int DFANext(std::string pat, int state, int c)
{
	int M = pat.length(); // Length of Pattern

	// If Input Character matches next character in Pattern
	if (state < M && c == pat[state]) 
		return state + 1; // Return Next State

	int next_state, i;

	// If Input Character matches any previous character in Pattern
	for (next_state = state; next_state > 0; next_state--)
	{
		if (pat[next_state - 1] == c)
		{
			for (i = 0 ; i < next_state - 1 ; i++)
				if (pat[i] != pat[state - next_state + 1 + i]) 
					break;
			if (i == next_state - 1) 
				return next_state; // Return Next State
		}
	}

	// If Input Character does not match any characters in Pattern
	return -1; // Default to -1
}

/**
 * @brief Builds a State Table based on the given Pattern
 * 
 * @param pat Pattern
 * @param dfa DFA
 */
void DFABuild(std::string pat, int dfa[][NO_OF_CHARS])
{
	int M = pat.length(); // Length of Pattern

	// Build DFA 
	for (int state{0} ; state <= M ; ++state)
	{
		// All 256 ACSII Characters
		for (int c{0} ; c < NO_OF_CHARS ; ++c)  
		{
			// Get Next State based on current state and character
			dfa[state][c] = DFANext(pat, state, c);
		}
	}
}

/**
 * @brief Searches for a given Pattern in a given Text
 * 
 * @param txt Text
 * @param pat Pattern
 */
void KMPSearch(std::string txt, std::string pat)
{
	int M = pat.length(); // Length of Pattern
	int N = txt.length(); // Length of Text
	int dfa[M + 1][NO_OF_CHARS]; // 2D Array of Integers

	// Function Call to Build DFA
	DFABuild(pat, dfa);

	// State Tracker
	int state{0};

	// Search through the Text
	for (int i{0}; i < N; i++)
	{
		// Advances State based on DFA
		state = dfa[state][txt[i]];

		// Display if Pattern was found
		if (state == M)
		{
			std::cout << "Pattern found at index " << i - M + 1 << std::endl;
			return; // Terminate Program
		}
		else if (i + 1 == N)
			std::cout << "Pattern not found" << std::endl;
	}
}

/**
 * @brief Driver for KMP Search
 * 
 * @return int 
 */
int main()
{
	// Text String to Search
	std::string txt = "BCBAABACAABABACAA";
	// Pattern String to be Searched for
	std::string pat = "ABABAC";

	KMPSearch(txt, pat);

	return 0;
}
