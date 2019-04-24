using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(dsweb.Startup))]
namespace dsweb
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
