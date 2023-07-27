
/*! Set variable species concentration. */
#define SET_VAR(ind_spec, qnt_Cspec) 			\
  if (ctl->qnt_Cspec >= 0)					\
    VAR[ind_spec] = atm->q[ctl->qnt_Cspec][ip];

/*! Get variable species concentration. */
#define GET_VAR(ind_spec, qnt_index)			\
  if (qnt_index >= 0)					\
    atm->q[qnt_index][ip] = VAR[ind_spec];

/*! Initialize concentration quantity. */
#define INIT_CQNT(qnt_index, clim_var_t)				\
  if (qnt_index >= 0)							\
    atm->q[qnt_index][ip] =						\
      clim_var(&clim_var_t, atm->time[ip], atm->lat[ip], atm->p[ip]);

/*! Initialize KPP chemistry. */
void kpp_chem_initialize(
  ctl_t * ctl,
  clim_t * clim,
  met_t * met0,
  met_t * met1,
  atm_t * atm,
  int ip);

/*! Save KPP results. */
void kpp_chem_output2atm(
  atm_t * atm,
  ctl_t * ctl,
  int ip);

/*! KPP integration function. */
void INTEGRATE(
  double TIN,
  double TOUT);