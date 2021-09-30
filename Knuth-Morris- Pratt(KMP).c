#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
char text[100], pattern[100];
void prefixSuffixArray(char* pat, int m, int* lps) {
int length = 0;
lps[0] = 0;
int i = 1;
while (i &lt; m) {
if (pat[i] == pat[length]) {
length++;
lps[i] = length;
i++;
} else {
if (length != 0)
length = lps[length - 1];
else {
lps[i] = 0;
i++;
}
}
}
}
void KMPAlgorithm(char* text, char* pattern) {
int m = strlen(pattern);
int n = strlen(text);
int lps[n];
prefixSuffixArray(pattern, m, lps);
int i = 0, j = 0;
while (i &lt; n) {
if (pattern[j] == text[i]) {
j++;
i++;
}
if (j == m) {
printf(&quot;\nPattern found at index %d&quot;, i - j);
j = lps[j - 1];
}

else if (i &lt; n &amp;&amp; pattern[j] != text[i]) {
if (j != 0)
j = lps[j - 1];
else
i = i + 1;
}
}
}
int main() {
printf(&quot;\n\t Implementation of Knuth-morris-pratt(kmp) \n&quot;);
printf(&quot;\nEnter the text:&quot;);
scanf(&quot;%[^\n]%*c&quot;, text);
printf(&quot;\nEnter the pattern:&quot;);
scanf(&quot;%[^\n]%*c&quot;, pattern);
KMPAlgorithm(text, pattern);
return 0;
}
