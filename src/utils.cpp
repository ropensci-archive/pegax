#include <Rcpp.h>
using namespace Rcpp;
#include <cassert>
#include <map>

std::map<std::string, std::string> charMapping(){
  const std::map<std::string, std::string> init {
    {"À", "A"},
    {"Â", "A"},
    {"Å", "A"},
    {"Ã", "A"},
    {"Ä", "A"},
    {"Á", "A"},
    {"Ç", "C"},
    {"Č", "C"},
    {"Ë", "E"},
    {"É", "E"},
    {"È", "E"},
    {"Í", "I"},
    {"Ì", "I"},
    {"Ï", "I"},
    {"Ň", "N"},
    {"Ñ", "N"},
    {"Ñ", "N"},
    {"Ó", "O"},
    {"Ò", "O"},
    {"Ô", "O"},
    {"Ø", "O"},
    {"Õ", "O"},
    {"Ö", "O"},
    {"Ú", "U"},
    {"Ù", "U"},
    {"Ü", "U"},
    {"Ŕ", "R"},
    {"Ř", "R"},
    {"Ŗ", "R"},
    {"Š", "S"},
    {"Š", "S"},
    {"Ş", "S"},
    {"Ž", "Z"},
    {"à", "a"},
    {"â", "a"},
    {"å", "a"},
    {"ã", "a"},
    {"ä", "a"},
    {"á", "a"},
    {"ç", "c"},
    {"č", "c"},
    {"ë", "e"},
    {"é", "e"},
    {"è", "e"},
    {"í", "i"},
    {"ì", "i"},
    {"ï", "i"},
    {"ň", "n"},
    {"ñ", "n"},
    {"ñ", "n"},
    {"ó", "o"},
    {"ò", "o"},
    {"ô", "o"},
    {"ø", "o"},
    {"õ", "o"},
    {"ö", "o"},
    {"ú", "u"},
    {"ù", "u"},
    {"ü", "u"},
    {"ŕ", "r"},
    {"ř", "r"},
    {"ŗ", "r"},
    {"ſ", "s"},
    {"š", "s"},
    {"š", "s"},
    {"ş", "s"},
    {"ž", "z"},
    {"Æ", "Ae"},
    {"Œ", "Oe"},
    {"æ", "ae"},
    {"œ", "oe"},
    {"Ö", "Oe"},
    {"\'", ""}
  };
  return(init);
}

// def normalizeAuthorWord(input: String): String = {
//   if (input.matches("""[\p{Lu}]{3,}[\p{Lu}-]*"""))
//     input.split("-").map { _.toLowerCase.capitalize }.mkString("-")
//   else input
// }
//
// def normalize(input: String): String = {
//   val output = new StringBuilder()
//   var inputIdx = 0
//   while (inputIdx < input.length) {
//     val chr = input.charAt(inputIdx)
//     if (inputIdx == 0 && chr.isDigit) {
//       while (input.charAt(inputIdx).isDigit) {
//         inputIdx += 1
//       }
//       output.append(numberToString(input.substring(0, inputIdx)))
//       if (Set('.', '-').contains(input.charAt(inputIdx))) {
//         inputIdx += 1
//       }
//     } else {
//       if (charMapping.contains(chr)) {
//         output.append(charMapping(chr))
//       } else {
//         output.append(chr)
//       }
//       inputIdx += 1
//     }
//   }
//   val res = output.toString.replaceFirst("""\?$""", "")
//   res
// }
//

std::string numberToString(int x) {
  switch (x) {
    case 1: return "uni";
    case 2: return "bi";
    case 3: return "tri";
    case 4: return "quadri";
    case 5: return "quinque";
    case 6: return "sex";
    case 7: return "septem";
    case 8: return "octo";
    case 9: return "novem";
    case 10: return "decem";
    case 11: return "undecim";
    case 12: return "duodecim";
    case 13: return "tredecim";
    case 14: return "quatuordecim";
    case 15: return "quindecim";
    case 16: return "sedecim";
    case 17: return "septendecim";
    case 18: return "octodecim";
    case 19: return "novemdecim";
    case 20: return "viginti";
    case 21: return "vigintiuno";
    case 22: return "vigintiduo";
    case 23: return "vigintitre";
    case 24: return "vigintiquatuor";
    case 25: return "vigintiquinque";
    case 26: return "vigintisex";
    case 27: return "vigintiseptem";
    case 28: return "vigintiocto";
    case 30: return "triginta";
    case 31: return "trigintauno";
    case 32: return "trigintaduo";
    case 38: return "trigintaocto";
    case 40: return "quadraginta";
    default: return std::to_string(x);
  };
};
