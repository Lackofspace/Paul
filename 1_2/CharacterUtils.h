#ifndef CHARACTERUTILS_H
#define CHARACTERUTILS_H

bool IsCharBelongsToPlaintextAlphabet(int charCode);
bool IsCharBelongsToKeyAlphabet(char c, const std::string& customEncoding);
int GetKeyCharCode(char c, const std::string& customEncoding);

#endif
