#define OPEN fout.open(filename)
#define INIT fout<<"<!DOCTYPE html>\n<html>\n<head>\n</head>\n<body>\n</body>\n</html>"
#define GOTOB fout.seekp(-16,ios_base::end);
#define GOTOH fout.seekp(-33,ios_base::end);
#define CLOSE fout.close()
#define STAB "border:1px solid black;border-collapse:collapse;"
#define SPAR "color:black;font:Arial;"
#define SHED "color:black;font:Arial;"
