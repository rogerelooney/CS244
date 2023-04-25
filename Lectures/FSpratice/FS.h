#ifndef FS_H
#define FS_H

namespace fileStreaming
{
    void copy(string src, string des)
    {
	    fstream in, out;
	    char ch;

	    in.open(src.data(),fstream::in);
	    out.open(des.data()fstream::out);

	    if(in.is_open())
	    {
		    while(in >> ch)
		    {
			    out << ch;
		    }
	    }
	    in.close();
	    out.close();
    }

    double DataAverage(string src)
    {
	    fstream in(src.data(), fstream::in);
	    double sum = 0;
	    int count = 0;

	    if(in.is_open())
	    {
		    double value;
		    while(in >> value)
		    {
			    sum = sum + value;
			    count += 1;
		    }
	    }
	    in.close();
	    return (count > 0)?(sum / count):(0.0);
    }
}

#endif