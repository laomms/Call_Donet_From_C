using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CLRHostLib
{
    public class ClrClass
    {
        public static int ClrExcute(string paramstr)
        {
            MessageBox.Show(paramstr);
            return 0;
        }

    }
}