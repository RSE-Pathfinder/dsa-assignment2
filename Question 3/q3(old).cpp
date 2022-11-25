/**
 * @file q3.cpp
 * @author Paul Yong (2102088@sit.singaporetech.edu.sg)
 * @brief 
 * 		Object Oriented Programming implementation of 
 * 		Knuth-Morris-Pratt Substring Search.
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
#include <iostream>
#include <string>

#define ARRAY_SIZE 256

namespace KMPSearch {
	class KMP {
		public:
			KMP( std::string pat, std::string txt );
		public:
			void Search();
		private:
			std::string m_pat;
			std::string m_txt;
			int M;
			int N;
			int* dfa;
	};
}

namespace KMPSearch {
	KMP::KMP( std::string pat, std::string txt ) : m_pat{pat}, m_txt{txt}, M{(int)pat.length()}, N{(int)txt.length()} 
	{
		dfa = new int[M];
		for (int i{0} ; i < M ; i++) dfa[i] = 0;
		
		int len{0}, i{1};
		while (i < M) {
			if (pat[i] == pat[len]) 
			{
				dfa[i++] = ++len;
			}
			else
			{
				if (len != 0) 
					len = dfa[len - 1];
				else dfa[i++] = 0;
			}
		}
	}

	void KMP::Search()
	{
		int i{0}; 
		int j{0}; 

		while ((N - i) >= (M - j)) {
			if (m_pat[j] == m_txt[i]) {
				j++;
				i++;
			}

			if (j == M) {
				break;
			}

			else if (i < N && m_pat[j] != m_txt[i]) {
				if (j != 0) j = dfa[j - 1];
				else i++;
			}
		}

		if (j == M)
			std::cout << "Found at index: " << i - j + 1 << std::endl;
		else
			std::cout << "Pattern was not found" << std::endl;
	}
}

int main()
{
	std::string txt = "BCBAABACAABABACAA";
	std::string pat = "ABABAC";

	std::cout << "Text:    " << txt << std::endl;
	std::cout << "Pattern: " << pat << std::endl;

	KMPSearch::KMP kmp = KMPSearch::KMP(pat, txt);
	kmp.Search();

	return 0;
}
