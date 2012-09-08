<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<title>Linux/drivers/cpufreq/cpufreq.c - Linux Cross Reference - Free Electrons</title>
<link rel="stylesheet" href="/style.css" type="text/css" media="screen" />
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<meta description="Linux Cross-Reference (LXR) service by Free Electrons. The easiest way to study Linux kernel sources. Available for all recent releases." />
<base href="http://lxr.free-electrons.com/"/>
</head>

<body>

<div id="wrapper">
<div id="wrapper2">
<div id="header">

	<div id="logo">
		<h1>Linux Cross Reference</h1>
		<h2><a href="http://free-electrons.com">Free Electrons</a></h2>
		<h2>Embedded Linux Experts</h2>
		<p>
		 &nbsp;&bull;&nbsp;<b><i>source navigation</i></b> &nbsp;&bull;&nbsp;<a href="diff/drivers/cpufreq/cpufreq.c">diff markup</a> &nbsp;&bull;&nbsp;<a href="ident">identifier search</a> &nbsp;&bull;&nbsp;<a href="search">freetext search</a> &nbsp;&bull;&nbsp;
		</p>
	</div>
</div>

<div id="topbar">
  
  <p>Version: &nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=2.6.30">2.6.30</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=2.6.31">2.6.31</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=2.6.32">2.6.32</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=2.6.33">2.6.33</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=2.6.34">2.6.34</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=2.6.35">2.6.35</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=2.6.36">2.6.36</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=2.6.37">2.6.37</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=2.6.38">2.6.38</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=2.6.39">2.6.39</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=3.0">3.0</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=3.1">3.1</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=3.2">3.2</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=3.3">3.3</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?v=3.4">3.4</a>&nbsp;<b><i>3.5</i></b></p>
  
  <p>Architecture: &nbsp;<b><i>x86</i></b>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?a=arm">arm</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?a=avr32">avr32</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?a=blackfin">blackfin</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?a=m68k">m68k</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?a=m68knommu">m68knommu</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?a=microblaze">microblaze</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?a=mips">mips</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?a=powerpc">powerpc</a>&nbsp;<a href="source/drivers/cpufreq/cpufreq.c?a=sh">sh</a></p>
  
</div>

<h1><a href="source/">Linux</a>/<a href="source/drivers/">drivers</a>/<a href="source/drivers/cpufreq/">cpufreq</a>/<a href="source/drivers/cpufreq/cpufreq.c">cpufreq.c</a></h1>
<div id="lxrcode"><pre>  <a name="L1" href="source/drivers/cpufreq/cpufreq.c#L1">1</a> <b><i>/*</i></b>
  <a name="L2" href="source/drivers/cpufreq/cpufreq.c#L2">2</a> <b><i> *  linux/drivers/cpufreq/cpufreq.c</i></b>
  <a name="L3" href="source/drivers/cpufreq/cpufreq.c#L3">3</a> <b><i> *</i></b>
  <a name="L4" href="source/drivers/cpufreq/cpufreq.c#L4">4</a> <b><i> *  Copyright (C) 2001 Russell King</i></b>
  <a name="L5" href="source/drivers/cpufreq/cpufreq.c#L5">5</a> <b><i> *            (C) 2002 - 2003 Dominik Brodowski &lt;linux@brodo.de&gt;</i></b>
  <a name="L6" href="source/drivers/cpufreq/cpufreq.c#L6">6</a> <b><i> *</i></b>
  <a name="L7" href="source/drivers/cpufreq/cpufreq.c#L7">7</a> <b><i> *  Oct 2005 - Ashok Raj &lt;ashok.raj@intel.com&gt;</i></b>
  <a name="L8" href="source/drivers/cpufreq/cpufreq.c#L8">8</a> <b><i> *      Added handling for CPU hotplug</i></b>
  <a name="L9" href="source/drivers/cpufreq/cpufreq.c#L9">9</a> <b><i> *  Feb 2006 - Jacob Shin &lt;jacob.shin@amd.com&gt;</i></b>
 <a name="L10" href="source/drivers/cpufreq/cpufreq.c#L10">10</a> <b><i> *      Fix handling for CPU hotplug -- affected CPUs</i></b>
 <a name="L11" href="source/drivers/cpufreq/cpufreq.c#L11">11</a> <b><i> *</i></b>
 <a name="L12" href="source/drivers/cpufreq/cpufreq.c#L12">12</a> <b><i> * This program is free software; you can redistribute it and/or modify</i></b>
 <a name="L13" href="source/drivers/cpufreq/cpufreq.c#L13">13</a> <b><i> * it under the terms of the GNU General Public License version 2 as</i></b>
 <a name="L14" href="source/drivers/cpufreq/cpufreq.c#L14">14</a> <b><i> * published by the Free Software Foundation.</i></b>
 <a name="L15" href="source/drivers/cpufreq/cpufreq.c#L15">15</a> <b><i> *</i></b>
 <a name="L16" href="source/drivers/cpufreq/cpufreq.c#L16">16</a> <b><i> */</i></b>
 <a name="L17" href="source/drivers/cpufreq/cpufreq.c#L17">17</a> 
 <a name="L18" href="source/drivers/cpufreq/cpufreq.c#L18">18</a> #include &lt;linux/kernel.h&gt;
 <a name="L19" href="source/drivers/cpufreq/cpufreq.c#L19">19</a> #include &lt;linux/module.h&gt;
 <a name="L20" href="source/drivers/cpufreq/cpufreq.c#L20">20</a> #include &lt;linux/init.h&gt;
 <a name="L21" href="source/drivers/cpufreq/cpufreq.c#L21">21</a> #include &lt;linux/notifier.h&gt;
 <a name="L22" href="source/drivers/cpufreq/cpufreq.c#L22">22</a> #include &lt;linux/cpufreq.h&gt;
 <a name="L23" href="source/drivers/cpufreq/cpufreq.c#L23">23</a> #include &lt;linux/delay.h&gt;
 <a name="L24" href="source/drivers/cpufreq/cpufreq.c#L24">24</a> #include &lt;linux/interrupt.h&gt;
 <a name="L25" href="source/drivers/cpufreq/cpufreq.c#L25">25</a> #include &lt;linux/spinlock.h&gt;
 <a name="L26" href="source/drivers/cpufreq/cpufreq.c#L26">26</a> #include &lt;linux/device.h&gt;
 <a name="L27" href="source/drivers/cpufreq/cpufreq.c#L27">27</a> #include &lt;linux/slab.h&gt;
 <a name="L28" href="source/drivers/cpufreq/cpufreq.c#L28">28</a> #include &lt;linux/cpu.h&gt;
 <a name="L29" href="source/drivers/cpufreq/cpufreq.c#L29">29</a> #include &lt;linux/completion.h&gt;
 <a name="L30" href="source/drivers/cpufreq/cpufreq.c#L30">30</a> #include &lt;linux/mutex.h&gt;
 <a name="L31" href="source/drivers/cpufreq/cpufreq.c#L31">31</a> #include &lt;linux/syscore_ops.h&gt;
 <a name="L32" href="source/drivers/cpufreq/cpufreq.c#L32">32</a> 
 <a name="L33" href="source/drivers/cpufreq/cpufreq.c#L33">33</a> #include &lt;trace/events/power.h&gt;
 <a name="L34" href="source/drivers/cpufreq/cpufreq.c#L34">34</a> 
 <a name="L35" href="source/drivers/cpufreq/cpufreq.c#L35">35</a> <b><i>/**</i></b>
 <a name="L36" href="source/drivers/cpufreq/cpufreq.c#L36">36</a> <b><i> * The "cpufreq driver" - the arch- or hardware-dependent low</i></b>
 <a name="L37" href="source/drivers/cpufreq/cpufreq.c#L37">37</a> <b><i> * level driver of CPUFreq support, and its spinlock. This lock</i></b>
 <a name="L38" href="source/drivers/cpufreq/cpufreq.c#L38">38</a> <b><i> * also protects the cpufreq_cpu_data array.</i></b>
 <a name="L39" href="source/drivers/cpufreq/cpufreq.c#L39">39</a> <b><i> */</i></b>
 <a name="L40" href="source/drivers/cpufreq/cpufreq.c#L40">40</a> static struct <a href="ident?i=cpufreq_driver">cpufreq_driver</a> *<a href="ident?i=cpufreq_driver">cpufreq_driver</a>;
 <a name="L41" href="source/drivers/cpufreq/cpufreq.c#L41">41</a> static <a href="ident?i=DEFINE_PER_CPU">DEFINE_PER_CPU</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *, cpufreq_cpu_data);
 <a name="L42" href="source/drivers/cpufreq/cpufreq.c#L42">42</a> #ifdef CONFIG_HOTPLUG_CPU
 <a name="L43" href="source/drivers/cpufreq/cpufreq.c#L43">43</a> <b><i>/* This one keeps track of the previously set governor of a removed CPU */</i></b>
 <a name="L44" href="source/drivers/cpufreq/cpufreq.c#L44">44</a> static <a href="ident?i=DEFINE_PER_CPU">DEFINE_PER_CPU</a>(char[<a href="ident?i=CPUFREQ_NAME_LEN">CPUFREQ_NAME_LEN</a>], cpufreq_cpu_governor);
 <a name="L45" href="source/drivers/cpufreq/cpufreq.c#L45">45</a> #endif
 <a name="L46" href="source/drivers/cpufreq/cpufreq.c#L46">46</a> static <a href="ident?i=DEFINE_SPINLOCK">DEFINE_SPINLOCK</a>(cpufreq_driver_lock);
 <a name="L47" href="source/drivers/cpufreq/cpufreq.c#L47">47</a> 
 <a name="L48" href="source/drivers/cpufreq/cpufreq.c#L48">48</a> <b><i>/*</i></b>
 <a name="L49" href="source/drivers/cpufreq/cpufreq.c#L49">49</a> <b><i> * cpu_policy_rwsem is a per CPU reader-writer semaphore designed to cure</i></b>
 <a name="L50" href="source/drivers/cpufreq/cpufreq.c#L50">50</a> <b><i> * all cpufreq/hotplug/workqueue/etc related lock issues.</i></b>
 <a name="L51" href="source/drivers/cpufreq/cpufreq.c#L51">51</a> <b><i> *</i></b>
 <a name="L52" href="source/drivers/cpufreq/cpufreq.c#L52">52</a> <b><i> * The rules for this semaphore:</i></b>
 <a name="L53" href="source/drivers/cpufreq/cpufreq.c#L53">53</a> <b><i> * - Any routine that wants to read from the policy structure will</i></b>
 <a name="L54" href="source/drivers/cpufreq/cpufreq.c#L54">54</a> <b><i> *   do a down_read on this semaphore.</i></b>
 <a name="L55" href="source/drivers/cpufreq/cpufreq.c#L55">55</a> <b><i> * - Any routine that will write to the policy structure and/or may take away</i></b>
 <a name="L56" href="source/drivers/cpufreq/cpufreq.c#L56">56</a> <b><i> *   the policy altogether (eg. CPU hotplug), will hold this lock in write</i></b>
 <a name="L57" href="source/drivers/cpufreq/cpufreq.c#L57">57</a> <b><i> *   mode before doing so.</i></b>
 <a name="L58" href="source/drivers/cpufreq/cpufreq.c#L58">58</a> <b><i> *</i></b>
 <a name="L59" href="source/drivers/cpufreq/cpufreq.c#L59">59</a> <b><i> * Additional rules:</i></b>
 <a name="L60" href="source/drivers/cpufreq/cpufreq.c#L60">60</a> <b><i> * - All holders of the lock should check to make sure that the CPU they</i></b>
 <a name="L61" href="source/drivers/cpufreq/cpufreq.c#L61">61</a> <b><i> *   are concerned with are online after they get the lock.</i></b>
 <a name="L62" href="source/drivers/cpufreq/cpufreq.c#L62">62</a> <b><i> * - Governor routines that can be called in cpufreq hotplug path should not</i></b>
 <a name="L63" href="source/drivers/cpufreq/cpufreq.c#L63">63</a> <b><i> *   take this sem as top level hotplug notifier handler takes this.</i></b>
 <a name="L64" href="source/drivers/cpufreq/cpufreq.c#L64">64</a> <b><i> * - Lock should not be held across</i></b>
 <a name="L65" href="source/drivers/cpufreq/cpufreq.c#L65">65</a> <b><i> *     __cpufreq_governor(data, CPUFREQ_GOV_STOP);</i></b>
 <a name="L66" href="source/drivers/cpufreq/cpufreq.c#L66">66</a> <b><i> */</i></b>
 <a name="L67" href="source/drivers/cpufreq/cpufreq.c#L67">67</a> static <a href="ident?i=DEFINE_PER_CPU">DEFINE_PER_CPU</a>(int, cpufreq_policy_cpu);
 <a name="L68" href="source/drivers/cpufreq/cpufreq.c#L68">68</a> static <a href="ident?i=DEFINE_PER_CPU">DEFINE_PER_CPU</a>(struct <a href="ident?i=rw_semaphore">rw_semaphore</a>, cpu_policy_rwsem);
 <a name="L69" href="source/drivers/cpufreq/cpufreq.c#L69">69</a> 
 <a name="L70" href="source/drivers/cpufreq/cpufreq.c#L70">70</a> #define <a href="ident?i=lock_policy_rwsem">lock_policy_rwsem</a>(<a href="ident?i=mode">mode</a>, <a href="ident?i=cpu">cpu</a>)                                    \
 <a name="L71" href="source/drivers/cpufreq/cpufreq.c#L71">71</a> static int lock_policy_rwsem_##mode                                     \
 <a name="L72" href="source/drivers/cpufreq/cpufreq.c#L72">72</a> (int <a href="ident?i=cpu">cpu</a>)                                                               \
 <a name="L73" href="source/drivers/cpufreq/cpufreq.c#L73">73</a> {                                                                       \
 <a name="L74" href="source/drivers/cpufreq/cpufreq.c#L74">74</a>         int policy_cpu = <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_policy_cpu, <a href="ident?i=cpu">cpu</a>);              \
 <a name="L75" href="source/drivers/cpufreq/cpufreq.c#L75">75</a>         <a href="ident?i=BUG_ON">BUG_ON</a>(policy_cpu == -1);                                       \
 <a name="L76" href="source/drivers/cpufreq/cpufreq.c#L76">76</a>         down_##mode(&amp;<a href="ident?i=per_cpu">per_cpu</a>(cpu_policy_rwsem, policy_cpu));            \
 <a name="L77" href="source/drivers/cpufreq/cpufreq.c#L77">77</a>         if (<a href="ident?i=unlikely">unlikely</a>(!<a href="ident?i=cpu_online">cpu_online</a>(<a href="ident?i=cpu">cpu</a>))) {                               \
 <a name="L78" href="source/drivers/cpufreq/cpufreq.c#L78">78</a>                 up_##mode(&amp;<a href="ident?i=per_cpu">per_cpu</a>(cpu_policy_rwsem, policy_cpu));      \
 <a name="L79" href="source/drivers/cpufreq/cpufreq.c#L79">79</a>                 return -1;                                              \
 <a name="L80" href="source/drivers/cpufreq/cpufreq.c#L80">80</a>         }                                                               \
 <a name="L81" href="source/drivers/cpufreq/cpufreq.c#L81">81</a>                                                                         \
 <a name="L82" href="source/drivers/cpufreq/cpufreq.c#L82">82</a>         return 0;                                                       \
 <a name="L83" href="source/drivers/cpufreq/cpufreq.c#L83">83</a> }
 <a name="L84" href="source/drivers/cpufreq/cpufreq.c#L84">84</a> 
 <a name="L85" href="source/drivers/cpufreq/cpufreq.c#L85">85</a> <a href="ident?i=lock_policy_rwsem">lock_policy_rwsem</a>(<a href="ident?i=read">read</a>, <a href="ident?i=cpu">cpu</a>);
 <a name="L86" href="source/drivers/cpufreq/cpufreq.c#L86">86</a> 
 <a name="L87" href="source/drivers/cpufreq/cpufreq.c#L87">87</a> <a href="ident?i=lock_policy_rwsem">lock_policy_rwsem</a>(<a href="ident?i=write">write</a>, <a href="ident?i=cpu">cpu</a>);
 <a name="L88" href="source/drivers/cpufreq/cpufreq.c#L88">88</a> 
 <a name="L89" href="source/drivers/cpufreq/cpufreq.c#L89">89</a> static void <a href="ident?i=unlock_policy_rwsem_read">unlock_policy_rwsem_read</a>(int <a href="ident?i=cpu">cpu</a>)
 <a name="L90" href="source/drivers/cpufreq/cpufreq.c#L90">90</a> {
 <a name="L91" href="source/drivers/cpufreq/cpufreq.c#L91">91</a>         int policy_cpu = <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_policy_cpu, <a href="ident?i=cpu">cpu</a>);
 <a name="L92" href="source/drivers/cpufreq/cpufreq.c#L92">92</a>         <a href="ident?i=BUG_ON">BUG_ON</a>(policy_cpu == -1);
 <a name="L93" href="source/drivers/cpufreq/cpufreq.c#L93">93</a>         <a href="ident?i=up_read">up_read</a>(&amp;<a href="ident?i=per_cpu">per_cpu</a>(cpu_policy_rwsem, policy_cpu));
 <a name="L94" href="source/drivers/cpufreq/cpufreq.c#L94">94</a> }
 <a name="L95" href="source/drivers/cpufreq/cpufreq.c#L95">95</a> 
 <a name="L96" href="source/drivers/cpufreq/cpufreq.c#L96">96</a> static void <a href="ident?i=unlock_policy_rwsem_write">unlock_policy_rwsem_write</a>(int <a href="ident?i=cpu">cpu</a>)
 <a name="L97" href="source/drivers/cpufreq/cpufreq.c#L97">97</a> {
 <a name="L98" href="source/drivers/cpufreq/cpufreq.c#L98">98</a>         int policy_cpu = <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_policy_cpu, <a href="ident?i=cpu">cpu</a>);
 <a name="L99" href="source/drivers/cpufreq/cpufreq.c#L99">99</a>         <a href="ident?i=BUG_ON">BUG_ON</a>(policy_cpu == -1);
<a name="L100" href="source/drivers/cpufreq/cpufreq.c#L100">100</a>         <a href="ident?i=up_write">up_write</a>(&amp;<a href="ident?i=per_cpu">per_cpu</a>(cpu_policy_rwsem, policy_cpu));
<a name="L101" href="source/drivers/cpufreq/cpufreq.c#L101">101</a> }
<a name="L102" href="source/drivers/cpufreq/cpufreq.c#L102">102</a> 
<a name="L103" href="source/drivers/cpufreq/cpufreq.c#L103">103</a> 
<a name="L104" href="source/drivers/cpufreq/cpufreq.c#L104">104</a> <b><i>/* internal prototypes */</i></b>
<a name="L105" href="source/drivers/cpufreq/cpufreq.c#L105">105</a> static int <a href="ident?i=__cpufreq_governor">__cpufreq_governor</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy,
<a name="L106" href="source/drivers/cpufreq/cpufreq.c#L106">106</a>                 unsigned int <a href="ident?i=event">event</a>);
<a name="L107" href="source/drivers/cpufreq/cpufreq.c#L107">107</a> static unsigned int <a href="ident?i=__cpufreq_get">__cpufreq_get</a>(unsigned int <a href="ident?i=cpu">cpu</a>);
<a name="L108" href="source/drivers/cpufreq/cpufreq.c#L108">108</a> static void <a href="ident?i=handle_update">handle_update</a>(struct <a href="ident?i=work_struct">work_struct</a> *<a href="ident?i=work">work</a>);
<a name="L109" href="source/drivers/cpufreq/cpufreq.c#L109">109</a> 
<a name="L110" href="source/drivers/cpufreq/cpufreq.c#L110">110</a> <b><i>/**</i></b>
<a name="L111" href="source/drivers/cpufreq/cpufreq.c#L111">111</a> <b><i> * Two notifier lists: the "policy" list is involved in the</i></b>
<a name="L112" href="source/drivers/cpufreq/cpufreq.c#L112">112</a> <b><i> * validation process for a new CPU frequency policy; the</i></b>
<a name="L113" href="source/drivers/cpufreq/cpufreq.c#L113">113</a> <b><i> * "transition" list for kernel code that needs to handle</i></b>
<a name="L114" href="source/drivers/cpufreq/cpufreq.c#L114">114</a> <b><i> * changes to devices when the CPU clock speed changes.</i></b>
<a name="L115" href="source/drivers/cpufreq/cpufreq.c#L115">115</a> <b><i> * The mutex locks both lists.</i></b>
<a name="L116" href="source/drivers/cpufreq/cpufreq.c#L116">116</a> <b><i> */</i></b>
<a name="L117" href="source/drivers/cpufreq/cpufreq.c#L117">117</a> static <a href="ident?i=BLOCKING_NOTIFIER_HEAD">BLOCKING_NOTIFIER_HEAD</a>(cpufreq_policy_notifier_list);
<a name="L118" href="source/drivers/cpufreq/cpufreq.c#L118">118</a> static struct <a href="ident?i=srcu_notifier_head">srcu_notifier_head</a> <a href="ident?i=cpufreq_transition_notifier_list">cpufreq_transition_notifier_list</a>;
<a name="L119" href="source/drivers/cpufreq/cpufreq.c#L119">119</a> 
<a name="L120" href="source/drivers/cpufreq/cpufreq.c#L120">120</a> static <a href="ident?i=bool">bool</a> <a href="ident?i=init_cpufreq_transition_notifier_list_called">init_cpufreq_transition_notifier_list_called</a>;
<a name="L121" href="source/drivers/cpufreq/cpufreq.c#L121">121</a> static int <a href="ident?i=__init">__init</a> <a href="ident?i=init_cpufreq_transition_notifier_list">init_cpufreq_transition_notifier_list</a>(void)
<a name="L122" href="source/drivers/cpufreq/cpufreq.c#L122">122</a> {
<a name="L123" href="source/drivers/cpufreq/cpufreq.c#L123">123</a>         <a href="ident?i=srcu_init_notifier_head">srcu_init_notifier_head</a>(&amp;<a href="ident?i=cpufreq_transition_notifier_list">cpufreq_transition_notifier_list</a>);
<a name="L124" href="source/drivers/cpufreq/cpufreq.c#L124">124</a>         <a href="ident?i=init_cpufreq_transition_notifier_list_called">init_cpufreq_transition_notifier_list_called</a> = <a href="ident?i=true">true</a>;
<a name="L125" href="source/drivers/cpufreq/cpufreq.c#L125">125</a>         return 0;
<a name="L126" href="source/drivers/cpufreq/cpufreq.c#L126">126</a> }
<a name="L127" href="source/drivers/cpufreq/cpufreq.c#L127">127</a> <a href="ident?i=pure_initcall">pure_initcall</a>(<a href="ident?i=init_cpufreq_transition_notifier_list">init_cpufreq_transition_notifier_list</a>);
<a name="L128" href="source/drivers/cpufreq/cpufreq.c#L128">128</a> 
<a name="L129" href="source/drivers/cpufreq/cpufreq.c#L129">129</a> static int <a href="ident?i=off">off</a> <a href="ident?i=__read_mostly">__read_mostly</a>;
<a name="L130" href="source/drivers/cpufreq/cpufreq.c#L130">130</a> int <a href="ident?i=cpufreq_disabled">cpufreq_disabled</a>(void)
<a name="L131" href="source/drivers/cpufreq/cpufreq.c#L131">131</a> {
<a name="L132" href="source/drivers/cpufreq/cpufreq.c#L132">132</a>         return <a href="ident?i=off">off</a>;
<a name="L133" href="source/drivers/cpufreq/cpufreq.c#L133">133</a> }
<a name="L134" href="source/drivers/cpufreq/cpufreq.c#L134">134</a> void <a href="ident?i=disable_cpufreq">disable_cpufreq</a>(void)
<a name="L135" href="source/drivers/cpufreq/cpufreq.c#L135">135</a> {
<a name="L136" href="source/drivers/cpufreq/cpufreq.c#L136">136</a>         <a href="ident?i=off">off</a> = 1;
<a name="L137" href="source/drivers/cpufreq/cpufreq.c#L137">137</a> }
<a name="L138" href="source/drivers/cpufreq/cpufreq.c#L138">138</a> static <a href="ident?i=LIST_HEAD">LIST_HEAD</a>(cpufreq_governor_list);
<a name="L139" href="source/drivers/cpufreq/cpufreq.c#L139">139</a> static <a href="ident?i=DEFINE_MUTEX">DEFINE_MUTEX</a>(cpufreq_governor_mutex);
<a name="L140" href="source/drivers/cpufreq/cpufreq.c#L140">140</a> 
<a name="L141" href="source/drivers/cpufreq/cpufreq.c#L141">141</a> struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *<a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(unsigned int <a href="ident?i=cpu">cpu</a>)
<a name="L142" href="source/drivers/cpufreq/cpufreq.c#L142">142</a> {
<a name="L143" href="source/drivers/cpufreq/cpufreq.c#L143">143</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *<a href="ident?i=data">data</a>;
<a name="L144" href="source/drivers/cpufreq/cpufreq.c#L144">144</a>         unsigned long <a href="ident?i=flags">flags</a>;
<a name="L145" href="source/drivers/cpufreq/cpufreq.c#L145">145</a> 
<a name="L146" href="source/drivers/cpufreq/cpufreq.c#L146">146</a>         if (<a href="ident?i=cpu">cpu</a> &gt;= <a href="ident?i=nr_cpu_ids">nr_cpu_ids</a>)
<a name="L147" href="source/drivers/cpufreq/cpufreq.c#L147">147</a>                 goto err_out;
<a name="L148" href="source/drivers/cpufreq/cpufreq.c#L148">148</a> 
<a name="L149" href="source/drivers/cpufreq/cpufreq.c#L149">149</a>         <b><i>/* get the cpufreq driver */</i></b>
<a name="L150" href="source/drivers/cpufreq/cpufreq.c#L150">150</a>         <a href="ident?i=spin_lock_irqsave">spin_lock_irqsave</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L151" href="source/drivers/cpufreq/cpufreq.c#L151">151</a> 
<a name="L152" href="source/drivers/cpufreq/cpufreq.c#L152">152</a>         if (!<a href="ident?i=cpufreq_driver">cpufreq_driver</a>)
<a name="L153" href="source/drivers/cpufreq/cpufreq.c#L153">153</a>                 goto err_out_unlock;
<a name="L154" href="source/drivers/cpufreq/cpufreq.c#L154">154</a> 
<a name="L155" href="source/drivers/cpufreq/cpufreq.c#L155">155</a>         if (!<a href="ident?i=try_module_get">try_module_get</a>(<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;owner))
<a name="L156" href="source/drivers/cpufreq/cpufreq.c#L156">156</a>                 goto err_out_unlock;
<a name="L157" href="source/drivers/cpufreq/cpufreq.c#L157">157</a> 
<a name="L158" href="source/drivers/cpufreq/cpufreq.c#L158">158</a> 
<a name="L159" href="source/drivers/cpufreq/cpufreq.c#L159">159</a>         <b><i>/* get the CPU */</i></b>
<a name="L160" href="source/drivers/cpufreq/cpufreq.c#L160">160</a>         <a href="ident?i=data">data</a> = <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_data, <a href="ident?i=cpu">cpu</a>);
<a name="L161" href="source/drivers/cpufreq/cpufreq.c#L161">161</a> 
<a name="L162" href="source/drivers/cpufreq/cpufreq.c#L162">162</a>         if (!<a href="ident?i=data">data</a>)
<a name="L163" href="source/drivers/cpufreq/cpufreq.c#L163">163</a>                 goto err_out_put_module;
<a name="L164" href="source/drivers/cpufreq/cpufreq.c#L164">164</a> 
<a name="L165" href="source/drivers/cpufreq/cpufreq.c#L165">165</a>         if (!<a href="ident?i=kobject_get">kobject_get</a>(&amp;<a href="ident?i=data">data</a>-&gt;<a href="ident?i=kobj">kobj</a>))
<a name="L166" href="source/drivers/cpufreq/cpufreq.c#L166">166</a>                 goto err_out_put_module;
<a name="L167" href="source/drivers/cpufreq/cpufreq.c#L167">167</a> 
<a name="L168" href="source/drivers/cpufreq/cpufreq.c#L168">168</a>         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L169" href="source/drivers/cpufreq/cpufreq.c#L169">169</a>         return <a href="ident?i=data">data</a>;
<a name="L170" href="source/drivers/cpufreq/cpufreq.c#L170">170</a> 
<a name="L171" href="source/drivers/cpufreq/cpufreq.c#L171">171</a> err_out_put_module:
<a name="L172" href="source/drivers/cpufreq/cpufreq.c#L172">172</a>         <a href="ident?i=module_put">module_put</a>(<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;owner);
<a name="L173" href="source/drivers/cpufreq/cpufreq.c#L173">173</a> err_out_unlock:
<a name="L174" href="source/drivers/cpufreq/cpufreq.c#L174">174</a>         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L175" href="source/drivers/cpufreq/cpufreq.c#L175">175</a> err_out:
<a name="L176" href="source/drivers/cpufreq/cpufreq.c#L176">176</a>         return <a href="ident?i=NULL">NULL</a>;
<a name="L177" href="source/drivers/cpufreq/cpufreq.c#L177">177</a> }
<a name="L178" href="source/drivers/cpufreq/cpufreq.c#L178">178</a> <a href="ident?i=EXPORT_SYMBOL_GPL">EXPORT_SYMBOL_GPL</a>(<a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>);
<a name="L179" href="source/drivers/cpufreq/cpufreq.c#L179">179</a> 
<a name="L180" href="source/drivers/cpufreq/cpufreq.c#L180">180</a> 
<a name="L181" href="source/drivers/cpufreq/cpufreq.c#L181">181</a> void <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *<a href="ident?i=data">data</a>)
<a name="L182" href="source/drivers/cpufreq/cpufreq.c#L182">182</a> {
<a name="L183" href="source/drivers/cpufreq/cpufreq.c#L183">183</a>         <a href="ident?i=kobject_put">kobject_put</a>(&amp;<a href="ident?i=data">data</a>-&gt;<a href="ident?i=kobj">kobj</a>);
<a name="L184" href="source/drivers/cpufreq/cpufreq.c#L184">184</a>         <a href="ident?i=module_put">module_put</a>(<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;owner);
<a name="L185" href="source/drivers/cpufreq/cpufreq.c#L185">185</a> }
<a name="L186" href="source/drivers/cpufreq/cpufreq.c#L186">186</a> <a href="ident?i=EXPORT_SYMBOL_GPL">EXPORT_SYMBOL_GPL</a>(<a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>);
<a name="L187" href="source/drivers/cpufreq/cpufreq.c#L187">187</a> 
<a name="L188" href="source/drivers/cpufreq/cpufreq.c#L188">188</a> 
<a name="L189" href="source/drivers/cpufreq/cpufreq.c#L189">189</a> <b><i>/*********************************************************************</i></b>
<a name="L190" href="source/drivers/cpufreq/cpufreq.c#L190">190</a> <b><i> *            EXTERNALLY AFFECTING FREQUENCY CHANGES                 *</i></b>
<a name="L191" href="source/drivers/cpufreq/cpufreq.c#L191">191</a> <b><i> *********************************************************************/</i></b>
<a name="L192" href="source/drivers/cpufreq/cpufreq.c#L192">192</a> 
<a name="L193" href="source/drivers/cpufreq/cpufreq.c#L193">193</a> <b><i>/**</i></b>
<a name="L194" href="source/drivers/cpufreq/cpufreq.c#L194">194</a> <b><i> * adjust_jiffies - adjust the system "loops_per_jiffy"</i></b>
<a name="L195" href="source/drivers/cpufreq/cpufreq.c#L195">195</a> <b><i> *</i></b>
<a name="L196" href="source/drivers/cpufreq/cpufreq.c#L196">196</a> <b><i> * This function alters the system "loops_per_jiffy" for the clock</i></b>
<a name="L197" href="source/drivers/cpufreq/cpufreq.c#L197">197</a> <b><i> * speed change. Note that loops_per_jiffy cannot be updated on SMP</i></b>
<a name="L198" href="source/drivers/cpufreq/cpufreq.c#L198">198</a> <b><i> * systems as each CPU might be scaled differently. So, use the arch</i></b>
<a name="L199" href="source/drivers/cpufreq/cpufreq.c#L199">199</a> <b><i> * per-CPU loops_per_jiffy value wherever possible.</i></b>
<a name="L200" href="source/drivers/cpufreq/cpufreq.c#L200">200</a> <b><i> */</i></b>
<a name="L201" href="source/drivers/cpufreq/cpufreq.c#L201">201</a> #ifndef <a href="ident?i=CONFIG_SMP">CONFIG_SMP</a>
<a name="L202" href="source/drivers/cpufreq/cpufreq.c#L202">202</a> static unsigned long <a href="ident?i=l_p_j_ref">l_p_j_ref</a>;
<a name="L203" href="source/drivers/cpufreq/cpufreq.c#L203">203</a> static unsigned int  <a href="ident?i=l_p_j_ref_freq">l_p_j_ref_freq</a>;
<a name="L204" href="source/drivers/cpufreq/cpufreq.c#L204">204</a> 
<a name="L205" href="source/drivers/cpufreq/cpufreq.c#L205">205</a> static void <a href="ident?i=adjust_jiffies">adjust_jiffies</a>(unsigned long <a href="ident?i=val">val</a>, struct <a href="ident?i=cpufreq_freqs">cpufreq_freqs</a> *ci)
<a name="L206" href="source/drivers/cpufreq/cpufreq.c#L206">206</a> {
<a name="L207" href="source/drivers/cpufreq/cpufreq.c#L207">207</a>         if (ci-&gt;<a href="ident?i=flags">flags</a> &amp; <a href="ident?i=CPUFREQ_CONST_LOOPS">CPUFREQ_CONST_LOOPS</a>)
<a name="L208" href="source/drivers/cpufreq/cpufreq.c#L208">208</a>                 return;
<a name="L209" href="source/drivers/cpufreq/cpufreq.c#L209">209</a> 
<a name="L210" href="source/drivers/cpufreq/cpufreq.c#L210">210</a>         if (!<a href="ident?i=l_p_j_ref_freq">l_p_j_ref_freq</a>) {
<a name="L211" href="source/drivers/cpufreq/cpufreq.c#L211">211</a>                 <a href="ident?i=l_p_j_ref">l_p_j_ref</a> = <a href="ident?i=loops_per_jiffy">loops_per_jiffy</a>;
<a name="L212" href="source/drivers/cpufreq/cpufreq.c#L212">212</a>                 <a href="ident?i=l_p_j_ref_freq">l_p_j_ref_freq</a> = ci-&gt;old;
<a name="L213" href="source/drivers/cpufreq/cpufreq.c#L213">213</a>                 <a href="ident?i=pr_debug">pr_debug</a>(<i>"saving %lu as reference value for loops_per_jiffy; "</i>
<a name="L214" href="source/drivers/cpufreq/cpufreq.c#L214">214</a>                         <i>"freq is %u kHz\n"</i>, <a href="ident?i=l_p_j_ref">l_p_j_ref</a>, <a href="ident?i=l_p_j_ref_freq">l_p_j_ref_freq</a>);
<a name="L215" href="source/drivers/cpufreq/cpufreq.c#L215">215</a>         }
<a name="L216" href="source/drivers/cpufreq/cpufreq.c#L216">216</a>         if ((<a href="ident?i=val">val</a> == <a href="ident?i=CPUFREQ_POSTCHANGE">CPUFREQ_POSTCHANGE</a>  &amp;&amp; ci-&gt;old != ci-&gt;new) ||
<a name="L217" href="source/drivers/cpufreq/cpufreq.c#L217">217</a>             (<a href="ident?i=val">val</a> == <a href="ident?i=CPUFREQ_RESUMECHANGE">CPUFREQ_RESUMECHANGE</a> || <a href="ident?i=val">val</a> == <a href="ident?i=CPUFREQ_SUSPENDCHANGE">CPUFREQ_SUSPENDCHANGE</a>)) {
<a name="L218" href="source/drivers/cpufreq/cpufreq.c#L218">218</a>                 <a href="ident?i=loops_per_jiffy">loops_per_jiffy</a> = <a href="ident?i=cpufreq_scale">cpufreq_scale</a>(<a href="ident?i=l_p_j_ref">l_p_j_ref</a>, <a href="ident?i=l_p_j_ref_freq">l_p_j_ref_freq</a>,
<a name="L219" href="source/drivers/cpufreq/cpufreq.c#L219">219</a>                                                                 ci-&gt;new);
<a name="L220" href="source/drivers/cpufreq/cpufreq.c#L220">220</a>                 <a href="ident?i=pr_debug">pr_debug</a>(<i>"scaling loops_per_jiffy to %lu "</i>
<a name="L221" href="source/drivers/cpufreq/cpufreq.c#L221">221</a>                         <i>"for frequency %u kHz\n"</i>, <a href="ident?i=loops_per_jiffy">loops_per_jiffy</a>, ci-&gt;new);
<a name="L222" href="source/drivers/cpufreq/cpufreq.c#L222">222</a>         }
<a name="L223" href="source/drivers/cpufreq/cpufreq.c#L223">223</a> }
<a name="L224" href="source/drivers/cpufreq/cpufreq.c#L224">224</a> #else
<a name="L225" href="source/drivers/cpufreq/cpufreq.c#L225">225</a> static inline void <a href="ident?i=adjust_jiffies">adjust_jiffies</a>(unsigned long <a href="ident?i=val">val</a>, struct <a href="ident?i=cpufreq_freqs">cpufreq_freqs</a> *ci)
<a name="L226" href="source/drivers/cpufreq/cpufreq.c#L226">226</a> {
<a name="L227" href="source/drivers/cpufreq/cpufreq.c#L227">227</a>         return;
<a name="L228" href="source/drivers/cpufreq/cpufreq.c#L228">228</a> }
<a name="L229" href="source/drivers/cpufreq/cpufreq.c#L229">229</a> #endif
<a name="L230" href="source/drivers/cpufreq/cpufreq.c#L230">230</a> 
<a name="L231" href="source/drivers/cpufreq/cpufreq.c#L231">231</a> 
<a name="L232" href="source/drivers/cpufreq/cpufreq.c#L232">232</a> <b><i>/**</i></b>
<a name="L233" href="source/drivers/cpufreq/cpufreq.c#L233">233</a> <b><i> * cpufreq_notify_transition - call notifier chain and adjust_jiffies</i></b>
<a name="L234" href="source/drivers/cpufreq/cpufreq.c#L234">234</a> <b><i> * on frequency transition.</i></b>
<a name="L235" href="source/drivers/cpufreq/cpufreq.c#L235">235</a> <b><i> *</i></b>
<a name="L236" href="source/drivers/cpufreq/cpufreq.c#L236">236</a> <b><i> * This function calls the transition notifiers and the "adjust_jiffies"</i></b>
<a name="L237" href="source/drivers/cpufreq/cpufreq.c#L237">237</a> <b><i> * function. It is called twice on all CPU frequency changes that have</i></b>
<a name="L238" href="source/drivers/cpufreq/cpufreq.c#L238">238</a> <b><i> * external effects.</i></b>
<a name="L239" href="source/drivers/cpufreq/cpufreq.c#L239">239</a> <b><i> */</i></b>
<a name="L240" href="source/drivers/cpufreq/cpufreq.c#L240">240</a> void <a href="ident?i=cpufreq_notify_transition">cpufreq_notify_transition</a>(struct <a href="ident?i=cpufreq_freqs">cpufreq_freqs</a> *<a href="ident?i=freqs">freqs</a>, unsigned int <a href="ident?i=state">state</a>)
<a name="L241" href="source/drivers/cpufreq/cpufreq.c#L241">241</a> {
<a name="L242" href="source/drivers/cpufreq/cpufreq.c#L242">242</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy;
<a name="L243" href="source/drivers/cpufreq/cpufreq.c#L243">243</a> 
<a name="L244" href="source/drivers/cpufreq/cpufreq.c#L244">244</a>         <a href="ident?i=BUG_ON">BUG_ON</a>(<a href="ident?i=irqs_disabled">irqs_disabled</a>());
<a name="L245" href="source/drivers/cpufreq/cpufreq.c#L245">245</a> 
<a name="L246" href="source/drivers/cpufreq/cpufreq.c#L246">246</a>         <a href="ident?i=freqs">freqs</a>-&gt;<a href="ident?i=flags">flags</a> = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=flags">flags</a>;
<a name="L247" href="source/drivers/cpufreq/cpufreq.c#L247">247</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"notification %u of frequency transition to %u kHz\n"</i>,
<a name="L248" href="source/drivers/cpufreq/cpufreq.c#L248">248</a>                 <a href="ident?i=state">state</a>, <a href="ident?i=freqs">freqs</a>-&gt;new);
<a name="L249" href="source/drivers/cpufreq/cpufreq.c#L249">249</a> 
<a name="L250" href="source/drivers/cpufreq/cpufreq.c#L250">250</a>         policy = <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_data, <a href="ident?i=freqs">freqs</a>-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L251" href="source/drivers/cpufreq/cpufreq.c#L251">251</a>         switch (<a href="ident?i=state">state</a>) {
<a name="L252" href="source/drivers/cpufreq/cpufreq.c#L252">252</a> 
<a name="L253" href="source/drivers/cpufreq/cpufreq.c#L253">253</a>         case <a href="ident?i=CPUFREQ_PRECHANGE">CPUFREQ_PRECHANGE</a>:
<a name="L254" href="source/drivers/cpufreq/cpufreq.c#L254">254</a>                 <b><i>/* detect if the driver reported a value as "old frequency"</i></b>
<a name="L255" href="source/drivers/cpufreq/cpufreq.c#L255">255</a> <b><i>                 * which is not equal to what the cpufreq core thinks is</i></b>
<a name="L256" href="source/drivers/cpufreq/cpufreq.c#L256">256</a> <b><i>                 * "old frequency".</i></b>
<a name="L257" href="source/drivers/cpufreq/cpufreq.c#L257">257</a> <b><i>                 */</i></b>
<a name="L258" href="source/drivers/cpufreq/cpufreq.c#L258">258</a>                 if (!(<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=flags">flags</a> &amp; <a href="ident?i=CPUFREQ_CONST_LOOPS">CPUFREQ_CONST_LOOPS</a>)) {
<a name="L259" href="source/drivers/cpufreq/cpufreq.c#L259">259</a>                         if ((policy) &amp;&amp; (policy-&gt;<a href="ident?i=cpu">cpu</a> == <a href="ident?i=freqs">freqs</a>-&gt;<a href="ident?i=cpu">cpu</a>) &amp;&amp;
<a name="L260" href="source/drivers/cpufreq/cpufreq.c#L260">260</a>                             (policy-&gt;cur) &amp;&amp; (policy-&gt;cur != <a href="ident?i=freqs">freqs</a>-&gt;old)) {
<a name="L261" href="source/drivers/cpufreq/cpufreq.c#L261">261</a>                                 <a href="ident?i=pr_debug">pr_debug</a>(<i>"Warning: CPU frequency is"</i>
<a name="L262" href="source/drivers/cpufreq/cpufreq.c#L262">262</a>                                         <i>" %u, cpufreq assumed %u kHz.\n"</i>,
<a name="L263" href="source/drivers/cpufreq/cpufreq.c#L263">263</a>                                         <a href="ident?i=freqs">freqs</a>-&gt;old, policy-&gt;cur);
<a name="L264" href="source/drivers/cpufreq/cpufreq.c#L264">264</a>                                 <a href="ident?i=freqs">freqs</a>-&gt;old = policy-&gt;cur;
<a name="L265" href="source/drivers/cpufreq/cpufreq.c#L265">265</a>                         }
<a name="L266" href="source/drivers/cpufreq/cpufreq.c#L266">266</a>                 }
<a name="L267" href="source/drivers/cpufreq/cpufreq.c#L267">267</a>                 <a href="ident?i=srcu_notifier_call_chain">srcu_notifier_call_chain</a>(&amp;<a href="ident?i=cpufreq_transition_notifier_list">cpufreq_transition_notifier_list</a>,
<a name="L268" href="source/drivers/cpufreq/cpufreq.c#L268">268</a>                                 <a href="ident?i=CPUFREQ_PRECHANGE">CPUFREQ_PRECHANGE</a>, <a href="ident?i=freqs">freqs</a>);
<a name="L269" href="source/drivers/cpufreq/cpufreq.c#L269">269</a>                 <a href="ident?i=adjust_jiffies">adjust_jiffies</a>(<a href="ident?i=CPUFREQ_PRECHANGE">CPUFREQ_PRECHANGE</a>, <a href="ident?i=freqs">freqs</a>);
<a name="L270" href="source/drivers/cpufreq/cpufreq.c#L270">270</a>                 break;
<a name="L271" href="source/drivers/cpufreq/cpufreq.c#L271">271</a> 
<a name="L272" href="source/drivers/cpufreq/cpufreq.c#L272">272</a>         case <a href="ident?i=CPUFREQ_POSTCHANGE">CPUFREQ_POSTCHANGE</a>:
<a name="L273" href="source/drivers/cpufreq/cpufreq.c#L273">273</a>                 <a href="ident?i=adjust_jiffies">adjust_jiffies</a>(<a href="ident?i=CPUFREQ_POSTCHANGE">CPUFREQ_POSTCHANGE</a>, <a href="ident?i=freqs">freqs</a>);
<a name="L274" href="source/drivers/cpufreq/cpufreq.c#L274">274</a>                 <a href="ident?i=pr_debug">pr_debug</a>(<i>"FREQ: %lu - CPU: %lu"</i>, (unsigned long)<a href="ident?i=freqs">freqs</a>-&gt;new,
<a name="L275" href="source/drivers/cpufreq/cpufreq.c#L275">275</a>                         (unsigned long)<a href="ident?i=freqs">freqs</a>-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L276" href="source/drivers/cpufreq/cpufreq.c#L276">276</a>                 <a href="ident?i=trace_power_frequency">trace_power_frequency</a>(POWER_PSTATE, <a href="ident?i=freqs">freqs</a>-&gt;new, <a href="ident?i=freqs">freqs</a>-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L277" href="source/drivers/cpufreq/cpufreq.c#L277">277</a>                 trace_cpu_frequency(<a href="ident?i=freqs">freqs</a>-&gt;new, <a href="ident?i=freqs">freqs</a>-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L278" href="source/drivers/cpufreq/cpufreq.c#L278">278</a>                 <a href="ident?i=srcu_notifier_call_chain">srcu_notifier_call_chain</a>(&amp;<a href="ident?i=cpufreq_transition_notifier_list">cpufreq_transition_notifier_list</a>,
<a name="L279" href="source/drivers/cpufreq/cpufreq.c#L279">279</a>                                 <a href="ident?i=CPUFREQ_POSTCHANGE">CPUFREQ_POSTCHANGE</a>, <a href="ident?i=freqs">freqs</a>);
<a name="L280" href="source/drivers/cpufreq/cpufreq.c#L280">280</a>                 if (<a href="ident?i=likely">likely</a>(policy) &amp;&amp; <a href="ident?i=likely">likely</a>(policy-&gt;<a href="ident?i=cpu">cpu</a> == <a href="ident?i=freqs">freqs</a>-&gt;<a href="ident?i=cpu">cpu</a>))
<a name="L281" href="source/drivers/cpufreq/cpufreq.c#L281">281</a>                         policy-&gt;cur = <a href="ident?i=freqs">freqs</a>-&gt;new;
<a name="L282" href="source/drivers/cpufreq/cpufreq.c#L282">282</a>                 break;
<a name="L283" href="source/drivers/cpufreq/cpufreq.c#L283">283</a>         }
<a name="L284" href="source/drivers/cpufreq/cpufreq.c#L284">284</a> }
<a name="L285" href="source/drivers/cpufreq/cpufreq.c#L285">285</a> <a href="ident?i=EXPORT_SYMBOL_GPL">EXPORT_SYMBOL_GPL</a>(<a href="ident?i=cpufreq_notify_transition">cpufreq_notify_transition</a>);
<a name="L286" href="source/drivers/cpufreq/cpufreq.c#L286">286</a> 
<a name="L287" href="source/drivers/cpufreq/cpufreq.c#L287">287</a> 
<a name="L288" href="source/drivers/cpufreq/cpufreq.c#L288">288</a> 
<a name="L289" href="source/drivers/cpufreq/cpufreq.c#L289">289</a> <b><i>/*********************************************************************</i></b>
<a name="L290" href="source/drivers/cpufreq/cpufreq.c#L290">290</a> <b><i> *                          SYSFS INTERFACE                          *</i></b>
<a name="L291" href="source/drivers/cpufreq/cpufreq.c#L291">291</a> <b><i> *********************************************************************/</i></b>
<a name="L292" href="source/drivers/cpufreq/cpufreq.c#L292">292</a> 
<a name="L293" href="source/drivers/cpufreq/cpufreq.c#L293">293</a> static struct <a href="ident?i=cpufreq_governor">cpufreq_governor</a> *<a href="ident?i=__find_governor">__find_governor</a>(const char *str_governor)
<a name="L294" href="source/drivers/cpufreq/cpufreq.c#L294">294</a> {
<a name="L295" href="source/drivers/cpufreq/cpufreq.c#L295">295</a>         struct <a href="ident?i=cpufreq_governor">cpufreq_governor</a> *<a href="ident?i=t">t</a>;
<a name="L296" href="source/drivers/cpufreq/cpufreq.c#L296">296</a> 
<a name="L297" href="source/drivers/cpufreq/cpufreq.c#L297">297</a>         <a href="ident?i=list_for_each_entry">list_for_each_entry</a>(<a href="ident?i=t">t</a>, &amp;cpufreq_governor_list, governor_list)
<a name="L298" href="source/drivers/cpufreq/cpufreq.c#L298">298</a>                 if (!<a href="ident?i=strnicmp">strnicmp</a>(str_governor, <a href="ident?i=t">t</a>-&gt;<a href="ident?i=name">name</a>, <a href="ident?i=CPUFREQ_NAME_LEN">CPUFREQ_NAME_LEN</a>))
<a name="L299" href="source/drivers/cpufreq/cpufreq.c#L299">299</a>                         return <a href="ident?i=t">t</a>;
<a name="L300" href="source/drivers/cpufreq/cpufreq.c#L300">300</a> 
<a name="L301" href="source/drivers/cpufreq/cpufreq.c#L301">301</a>         return <a href="ident?i=NULL">NULL</a>;
<a name="L302" href="source/drivers/cpufreq/cpufreq.c#L302">302</a> }
<a name="L303" href="source/drivers/cpufreq/cpufreq.c#L303">303</a> 
<a name="L304" href="source/drivers/cpufreq/cpufreq.c#L304">304</a> <b><i>/**</i></b>
<a name="L305" href="source/drivers/cpufreq/cpufreq.c#L305">305</a> <b><i> * cpufreq_parse_governor - parse a governor string</i></b>
<a name="L306" href="source/drivers/cpufreq/cpufreq.c#L306">306</a> <b><i> */</i></b>
<a name="L307" href="source/drivers/cpufreq/cpufreq.c#L307">307</a> static int <a href="ident?i=cpufreq_parse_governor">cpufreq_parse_governor</a>(char *str_governor, unsigned int *policy,
<a name="L308" href="source/drivers/cpufreq/cpufreq.c#L308">308</a>                                 struct <a href="ident?i=cpufreq_governor">cpufreq_governor</a> **governor)
<a name="L309" href="source/drivers/cpufreq/cpufreq.c#L309">309</a> {
<a name="L310" href="source/drivers/cpufreq/cpufreq.c#L310">310</a>         int <a href="ident?i=err">err</a> = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L311" href="source/drivers/cpufreq/cpufreq.c#L311">311</a> 
<a name="L312" href="source/drivers/cpufreq/cpufreq.c#L312">312</a>         if (!<a href="ident?i=cpufreq_driver">cpufreq_driver</a>)
<a name="L313" href="source/drivers/cpufreq/cpufreq.c#L313">313</a>                 goto <a href="ident?i=out">out</a>;
<a name="L314" href="source/drivers/cpufreq/cpufreq.c#L314">314</a> 
<a name="L315" href="source/drivers/cpufreq/cpufreq.c#L315">315</a>         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;setpolicy) {
<a name="L316" href="source/drivers/cpufreq/cpufreq.c#L316">316</a>                 if (!<a href="ident?i=strnicmp">strnicmp</a>(str_governor, <i>"performance"</i>, <a href="ident?i=CPUFREQ_NAME_LEN">CPUFREQ_NAME_LEN</a>)) {
<a name="L317" href="source/drivers/cpufreq/cpufreq.c#L317">317</a>                         *policy = <a href="ident?i=CPUFREQ_POLICY_PERFORMANCE">CPUFREQ_POLICY_PERFORMANCE</a>;
<a name="L318" href="source/drivers/cpufreq/cpufreq.c#L318">318</a>                         <a href="ident?i=err">err</a> = 0;
<a name="L319" href="source/drivers/cpufreq/cpufreq.c#L319">319</a>                 } else if (!<a href="ident?i=strnicmp">strnicmp</a>(str_governor, <i>"powersave"</i>,
<a name="L320" href="source/drivers/cpufreq/cpufreq.c#L320">320</a>                                                 <a href="ident?i=CPUFREQ_NAME_LEN">CPUFREQ_NAME_LEN</a>)) {
<a name="L321" href="source/drivers/cpufreq/cpufreq.c#L321">321</a>                         *policy = <a href="ident?i=CPUFREQ_POLICY_POWERSAVE">CPUFREQ_POLICY_POWERSAVE</a>;
<a name="L322" href="source/drivers/cpufreq/cpufreq.c#L322">322</a>                         <a href="ident?i=err">err</a> = 0;
<a name="L323" href="source/drivers/cpufreq/cpufreq.c#L323">323</a>                 }
<a name="L324" href="source/drivers/cpufreq/cpufreq.c#L324">324</a>         } else if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=target">target</a>) {
<a name="L325" href="source/drivers/cpufreq/cpufreq.c#L325">325</a>                 struct <a href="ident?i=cpufreq_governor">cpufreq_governor</a> *<a href="ident?i=t">t</a>;
<a name="L326" href="source/drivers/cpufreq/cpufreq.c#L326">326</a> 
<a name="L327" href="source/drivers/cpufreq/cpufreq.c#L327">327</a>                 <a href="ident?i=mutex_lock">mutex_lock</a>(&amp;cpufreq_governor_mutex);
<a name="L328" href="source/drivers/cpufreq/cpufreq.c#L328">328</a> 
<a name="L329" href="source/drivers/cpufreq/cpufreq.c#L329">329</a>                 <a href="ident?i=t">t</a> = <a href="ident?i=__find_governor">__find_governor</a>(str_governor);
<a name="L330" href="source/drivers/cpufreq/cpufreq.c#L330">330</a> 
<a name="L331" href="source/drivers/cpufreq/cpufreq.c#L331">331</a>                 if (<a href="ident?i=t">t</a> == <a href="ident?i=NULL">NULL</a>) {
<a name="L332" href="source/drivers/cpufreq/cpufreq.c#L332">332</a>                         int <a href="ident?i=ret">ret</a>;
<a name="L333" href="source/drivers/cpufreq/cpufreq.c#L333">333</a> 
<a name="L334" href="source/drivers/cpufreq/cpufreq.c#L334">334</a>                         <a href="ident?i=mutex_unlock">mutex_unlock</a>(&amp;cpufreq_governor_mutex);
<a name="L335" href="source/drivers/cpufreq/cpufreq.c#L335">335</a>                         <a href="ident?i=ret">ret</a> = <a href="ident?i=request_module">request_module</a>(<i>"cpufreq_%s"</i>, str_governor);
<a name="L336" href="source/drivers/cpufreq/cpufreq.c#L336">336</a>                         <a href="ident?i=mutex_lock">mutex_lock</a>(&amp;cpufreq_governor_mutex);
<a name="L337" href="source/drivers/cpufreq/cpufreq.c#L337">337</a> 
<a name="L338" href="source/drivers/cpufreq/cpufreq.c#L338">338</a>                         if (<a href="ident?i=ret">ret</a> == 0)
<a name="L339" href="source/drivers/cpufreq/cpufreq.c#L339">339</a>                                 <a href="ident?i=t">t</a> = <a href="ident?i=__find_governor">__find_governor</a>(str_governor);
<a name="L340" href="source/drivers/cpufreq/cpufreq.c#L340">340</a>                 }
<a name="L341" href="source/drivers/cpufreq/cpufreq.c#L341">341</a> 
<a name="L342" href="source/drivers/cpufreq/cpufreq.c#L342">342</a>                 if (<a href="ident?i=t">t</a> != <a href="ident?i=NULL">NULL</a>) {
<a name="L343" href="source/drivers/cpufreq/cpufreq.c#L343">343</a>                         *governor = <a href="ident?i=t">t</a>;
<a name="L344" href="source/drivers/cpufreq/cpufreq.c#L344">344</a>                         <a href="ident?i=err">err</a> = 0;
<a name="L345" href="source/drivers/cpufreq/cpufreq.c#L345">345</a>                 }
<a name="L346" href="source/drivers/cpufreq/cpufreq.c#L346">346</a> 
<a name="L347" href="source/drivers/cpufreq/cpufreq.c#L347">347</a>                 <a href="ident?i=mutex_unlock">mutex_unlock</a>(&amp;cpufreq_governor_mutex);
<a name="L348" href="source/drivers/cpufreq/cpufreq.c#L348">348</a>         }
<a name="L349" href="source/drivers/cpufreq/cpufreq.c#L349">349</a> <a href="ident?i=out">out</a>:
<a name="L350" href="source/drivers/cpufreq/cpufreq.c#L350">350</a>         return <a href="ident?i=err">err</a>;
<a name="L351" href="source/drivers/cpufreq/cpufreq.c#L351">351</a> }
<a name="L352" href="source/drivers/cpufreq/cpufreq.c#L352">352</a> 
<a name="L353" href="source/drivers/cpufreq/cpufreq.c#L353">353</a> 
<a name="L354" href="source/drivers/cpufreq/cpufreq.c#L354">354</a> <b><i>/**</i></b>
<a name="L355" href="source/drivers/cpufreq/cpufreq.c#L355">355</a> <b><i> * cpufreq_per_cpu_attr_read() / show_##file_name() -</i></b>
<a name="L356" href="source/drivers/cpufreq/cpufreq.c#L356">356</a> <b><i> * print out cpufreq information</i></b>
<a name="L357" href="source/drivers/cpufreq/cpufreq.c#L357">357</a> <b><i> *</i></b>
<a name="L358" href="source/drivers/cpufreq/cpufreq.c#L358">358</a> <b><i> * Write out information from cpufreq_driver-&gt;policy[cpu]; object must be</i></b>
<a name="L359" href="source/drivers/cpufreq/cpufreq.c#L359">359</a> <b><i> * "unsigned int".</i></b>
<a name="L360" href="source/drivers/cpufreq/cpufreq.c#L360">360</a> <b><i> */</i></b>
<a name="L361" href="source/drivers/cpufreq/cpufreq.c#L361">361</a> 
<a name="L362" href="source/drivers/cpufreq/cpufreq.c#L362">362</a> #define <a href="ident?i=show_one">show_one</a>(<a href="ident?i=file_name">file_name</a>, object)                     \
<a name="L363" href="source/drivers/cpufreq/cpufreq.c#L363">363</a> static <a href="ident?i=ssize_t">ssize_t</a> show_##file_name                         \
<a name="L364" href="source/drivers/cpufreq/cpufreq.c#L364">364</a> (struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy, char *<a href="ident?i=buf">buf</a>)              \
<a name="L365" href="source/drivers/cpufreq/cpufreq.c#L365">365</a> {                                                       \
<a name="L366" href="source/drivers/cpufreq/cpufreq.c#L366">366</a>         return <a href="ident?i=sprintf">sprintf</a>(<a href="ident?i=buf">buf</a>, <i>"%u\n"</i>, policy-&gt;object);    \
<a name="L367" href="source/drivers/cpufreq/cpufreq.c#L367">367</a> }
<a name="L368" href="source/drivers/cpufreq/cpufreq.c#L368">368</a> 
<a name="L369" href="source/drivers/cpufreq/cpufreq.c#L369">369</a> <a href="ident?i=show_one">show_one</a>(cpuinfo_min_freq, <a href="ident?i=cpuinfo">cpuinfo</a>.<a href="ident?i=min_freq">min_freq</a>);
<a name="L370" href="source/drivers/cpufreq/cpufreq.c#L370">370</a> <a href="ident?i=show_one">show_one</a>(cpuinfo_max_freq, <a href="ident?i=cpuinfo">cpuinfo</a>.<a href="ident?i=max_freq">max_freq</a>);
<a name="L371" href="source/drivers/cpufreq/cpufreq.c#L371">371</a> <a href="ident?i=show_one">show_one</a>(cpuinfo_transition_latency, <a href="ident?i=cpuinfo">cpuinfo</a>.<a href="ident?i=transition_latency">transition_latency</a>);
<a name="L372" href="source/drivers/cpufreq/cpufreq.c#L372">372</a> <a href="ident?i=show_one">show_one</a>(scaling_min_freq, <a href="ident?i=min">min</a>);
<a name="L373" href="source/drivers/cpufreq/cpufreq.c#L373">373</a> <a href="ident?i=show_one">show_one</a>(scaling_max_freq, <a href="ident?i=max">max</a>);
<a name="L374" href="source/drivers/cpufreq/cpufreq.c#L374">374</a> <a href="ident?i=show_one">show_one</a>(scaling_cur_freq, cur);
<a name="L375" href="source/drivers/cpufreq/cpufreq.c#L375">375</a> 
<a name="L376" href="source/drivers/cpufreq/cpufreq.c#L376">376</a> static int <a href="ident?i=__cpufreq_set_policy">__cpufreq_set_policy</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *<a href="ident?i=data">data</a>,
<a name="L377" href="source/drivers/cpufreq/cpufreq.c#L377">377</a>                                 struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy);
<a name="L378" href="source/drivers/cpufreq/cpufreq.c#L378">378</a> 
<a name="L379" href="source/drivers/cpufreq/cpufreq.c#L379">379</a> <b><i>/**</i></b>
<a name="L380" href="source/drivers/cpufreq/cpufreq.c#L380">380</a> <b><i> * cpufreq_per_cpu_attr_write() / store_##file_name() - sysfs write access</i></b>
<a name="L381" href="source/drivers/cpufreq/cpufreq.c#L381">381</a> <b><i> */</i></b>
<a name="L382" href="source/drivers/cpufreq/cpufreq.c#L382">382</a> #define <a href="ident?i=store_one">store_one</a>(<a href="ident?i=file_name">file_name</a>, object)                    \
<a name="L383" href="source/drivers/cpufreq/cpufreq.c#L383">383</a> static <a href="ident?i=ssize_t">ssize_t</a> store_##file_name                                        \
<a name="L384" href="source/drivers/cpufreq/cpufreq.c#L384">384</a> (struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy, const char *<a href="ident?i=buf">buf</a>, <a href="ident?i=size_t">size_t</a> <a href="ident?i=count">count</a>)          \
<a name="L385" href="source/drivers/cpufreq/cpufreq.c#L385">385</a> {                                                                       \
<a name="L386" href="source/drivers/cpufreq/cpufreq.c#L386">386</a>         unsigned int <a href="ident?i=ret">ret</a> = -<a href="ident?i=EINVAL">EINVAL</a>;                                     \
<a name="L387" href="source/drivers/cpufreq/cpufreq.c#L387">387</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> new_policy;                               \
<a name="L388" href="source/drivers/cpufreq/cpufreq.c#L388">388</a>                                                                         \
<a name="L389" href="source/drivers/cpufreq/cpufreq.c#L389">389</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_get_policy">cpufreq_get_policy</a>(&amp;new_policy, policy-&gt;<a href="ident?i=cpu">cpu</a>);             \
<a name="L390" href="source/drivers/cpufreq/cpufreq.c#L390">390</a>         if (<a href="ident?i=ret">ret</a>)                                                        \
<a name="L391" href="source/drivers/cpufreq/cpufreq.c#L391">391</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;                                         \
<a name="L392" href="source/drivers/cpufreq/cpufreq.c#L392">392</a>                                                                         \
<a name="L393" href="source/drivers/cpufreq/cpufreq.c#L393">393</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=sscanf">sscanf</a>(<a href="ident?i=buf">buf</a>, <i>"%u"</i>, &amp;new_policy.object);                    \
<a name="L394" href="source/drivers/cpufreq/cpufreq.c#L394">394</a>         if (<a href="ident?i=ret">ret</a> != 1)                                                   \
<a name="L395" href="source/drivers/cpufreq/cpufreq.c#L395">395</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;                                         \
<a name="L396" href="source/drivers/cpufreq/cpufreq.c#L396">396</a>                                                                         \
<a name="L397" href="source/drivers/cpufreq/cpufreq.c#L397">397</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=__cpufreq_set_policy">__cpufreq_set_policy</a>(policy, &amp;new_policy);                \
<a name="L398" href="source/drivers/cpufreq/cpufreq.c#L398">398</a>         policy-&gt;user_policy.object = policy-&gt;object;                    \
<a name="L399" href="source/drivers/cpufreq/cpufreq.c#L399">399</a>                                                                         \
<a name="L400" href="source/drivers/cpufreq/cpufreq.c#L400">400</a>         return <a href="ident?i=ret">ret</a> ? <a href="ident?i=ret">ret</a> : <a href="ident?i=count">count</a>;                                       \
<a name="L401" href="source/drivers/cpufreq/cpufreq.c#L401">401</a> }
<a name="L402" href="source/drivers/cpufreq/cpufreq.c#L402">402</a> 
<a name="L403" href="source/drivers/cpufreq/cpufreq.c#L403">403</a> <a href="ident?i=store_one">store_one</a>(scaling_min_freq, <a href="ident?i=min">min</a>);
<a name="L404" href="source/drivers/cpufreq/cpufreq.c#L404">404</a> <a href="ident?i=store_one">store_one</a>(scaling_max_freq, <a href="ident?i=max">max</a>);
<a name="L405" href="source/drivers/cpufreq/cpufreq.c#L405">405</a> 
<a name="L406" href="source/drivers/cpufreq/cpufreq.c#L406">406</a> <b><i>/**</i></b>
<a name="L407" href="source/drivers/cpufreq/cpufreq.c#L407">407</a> <b><i> * show_cpuinfo_cur_freq - current CPU frequency as detected by hardware</i></b>
<a name="L408" href="source/drivers/cpufreq/cpufreq.c#L408">408</a> <b><i> */</i></b>
<a name="L409" href="source/drivers/cpufreq/cpufreq.c#L409">409</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=show_cpuinfo_cur_freq">show_cpuinfo_cur_freq</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy,
<a name="L410" href="source/drivers/cpufreq/cpufreq.c#L410">410</a>                                         char *<a href="ident?i=buf">buf</a>)
<a name="L411" href="source/drivers/cpufreq/cpufreq.c#L411">411</a> {
<a name="L412" href="source/drivers/cpufreq/cpufreq.c#L412">412</a>         unsigned int <a href="ident?i=cur_freq">cur_freq</a> = <a href="ident?i=__cpufreq_get">__cpufreq_get</a>(policy-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L413" href="source/drivers/cpufreq/cpufreq.c#L413">413</a>         if (!<a href="ident?i=cur_freq">cur_freq</a>)
<a name="L414" href="source/drivers/cpufreq/cpufreq.c#L414">414</a>                 return <a href="ident?i=sprintf">sprintf</a>(<a href="ident?i=buf">buf</a>, <i>"&lt;unknown&gt;"</i>);
<a name="L415" href="source/drivers/cpufreq/cpufreq.c#L415">415</a>         return <a href="ident?i=sprintf">sprintf</a>(<a href="ident?i=buf">buf</a>, <i>"%u\n"</i>, <a href="ident?i=cur_freq">cur_freq</a>);
<a name="L416" href="source/drivers/cpufreq/cpufreq.c#L416">416</a> }
<a name="L417" href="source/drivers/cpufreq/cpufreq.c#L417">417</a> 
<a name="L418" href="source/drivers/cpufreq/cpufreq.c#L418">418</a> 
<a name="L419" href="source/drivers/cpufreq/cpufreq.c#L419">419</a> <b><i>/**</i></b>
<a name="L420" href="source/drivers/cpufreq/cpufreq.c#L420">420</a> <b><i> * show_scaling_governor - show the current policy for the specified CPU</i></b>
<a name="L421" href="source/drivers/cpufreq/cpufreq.c#L421">421</a> <b><i> */</i></b>
<a name="L422" href="source/drivers/cpufreq/cpufreq.c#L422">422</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=show_scaling_governor">show_scaling_governor</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy, char *<a href="ident?i=buf">buf</a>)
<a name="L423" href="source/drivers/cpufreq/cpufreq.c#L423">423</a> {
<a name="L424" href="source/drivers/cpufreq/cpufreq.c#L424">424</a>         if (policy-&gt;policy == <a href="ident?i=CPUFREQ_POLICY_POWERSAVE">CPUFREQ_POLICY_POWERSAVE</a>)
<a name="L425" href="source/drivers/cpufreq/cpufreq.c#L425">425</a>                 return <a href="ident?i=sprintf">sprintf</a>(<a href="ident?i=buf">buf</a>, <i>"powersave\n"</i>);
<a name="L426" href="source/drivers/cpufreq/cpufreq.c#L426">426</a>         else if (policy-&gt;policy == <a href="ident?i=CPUFREQ_POLICY_PERFORMANCE">CPUFREQ_POLICY_PERFORMANCE</a>)
<a name="L427" href="source/drivers/cpufreq/cpufreq.c#L427">427</a>                 return <a href="ident?i=sprintf">sprintf</a>(<a href="ident?i=buf">buf</a>, <i>"performance\n"</i>);
<a name="L428" href="source/drivers/cpufreq/cpufreq.c#L428">428</a>         else if (policy-&gt;governor)
<a name="L429" href="source/drivers/cpufreq/cpufreq.c#L429">429</a>                 return <a href="ident?i=scnprintf">scnprintf</a>(<a href="ident?i=buf">buf</a>, <a href="ident?i=CPUFREQ_NAME_LEN">CPUFREQ_NAME_LEN</a>, <i>"%s\n"</i>,
<a name="L430" href="source/drivers/cpufreq/cpufreq.c#L430">430</a>                                 policy-&gt;governor-&gt;<a href="ident?i=name">name</a>);
<a name="L431" href="source/drivers/cpufreq/cpufreq.c#L431">431</a>         return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L432" href="source/drivers/cpufreq/cpufreq.c#L432">432</a> }
<a name="L433" href="source/drivers/cpufreq/cpufreq.c#L433">433</a> 
<a name="L434" href="source/drivers/cpufreq/cpufreq.c#L434">434</a> 
<a name="L435" href="source/drivers/cpufreq/cpufreq.c#L435">435</a> <b><i>/**</i></b>
<a name="L436" href="source/drivers/cpufreq/cpufreq.c#L436">436</a> <b><i> * store_scaling_governor - store policy for the specified CPU</i></b>
<a name="L437" href="source/drivers/cpufreq/cpufreq.c#L437">437</a> <b><i> */</i></b>
<a name="L438" href="source/drivers/cpufreq/cpufreq.c#L438">438</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=store_scaling_governor">store_scaling_governor</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy,
<a name="L439" href="source/drivers/cpufreq/cpufreq.c#L439">439</a>                                         const char *<a href="ident?i=buf">buf</a>, <a href="ident?i=size_t">size_t</a> <a href="ident?i=count">count</a>)
<a name="L440" href="source/drivers/cpufreq/cpufreq.c#L440">440</a> {
<a name="L441" href="source/drivers/cpufreq/cpufreq.c#L441">441</a>         unsigned int <a href="ident?i=ret">ret</a> = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L442" href="source/drivers/cpufreq/cpufreq.c#L442">442</a>         char    str_governor[16];
<a name="L443" href="source/drivers/cpufreq/cpufreq.c#L443">443</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> new_policy;
<a name="L444" href="source/drivers/cpufreq/cpufreq.c#L444">444</a> 
<a name="L445" href="source/drivers/cpufreq/cpufreq.c#L445">445</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_get_policy">cpufreq_get_policy</a>(&amp;new_policy, policy-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L446" href="source/drivers/cpufreq/cpufreq.c#L446">446</a>         if (<a href="ident?i=ret">ret</a>)
<a name="L447" href="source/drivers/cpufreq/cpufreq.c#L447">447</a>                 return <a href="ident?i=ret">ret</a>;
<a name="L448" href="source/drivers/cpufreq/cpufreq.c#L448">448</a> 
<a name="L449" href="source/drivers/cpufreq/cpufreq.c#L449">449</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=sscanf">sscanf</a>(<a href="ident?i=buf">buf</a>, <i>"%15s"</i>, str_governor);
<a name="L450" href="source/drivers/cpufreq/cpufreq.c#L450">450</a>         if (<a href="ident?i=ret">ret</a> != 1)
<a name="L451" href="source/drivers/cpufreq/cpufreq.c#L451">451</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L452" href="source/drivers/cpufreq/cpufreq.c#L452">452</a> 
<a name="L453" href="source/drivers/cpufreq/cpufreq.c#L453">453</a>         if (<a href="ident?i=cpufreq_parse_governor">cpufreq_parse_governor</a>(str_governor, &amp;new_policy.policy,
<a name="L454" href="source/drivers/cpufreq/cpufreq.c#L454">454</a>                                                 &amp;new_policy.governor))
<a name="L455" href="source/drivers/cpufreq/cpufreq.c#L455">455</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L456" href="source/drivers/cpufreq/cpufreq.c#L456">456</a> 
<a name="L457" href="source/drivers/cpufreq/cpufreq.c#L457">457</a>         <b><i>/* Do not use cpufreq_set_policy here or the user_policy.max</i></b>
<a name="L458" href="source/drivers/cpufreq/cpufreq.c#L458">458</a> <b><i>           will be wrongly overridden */</i></b>
<a name="L459" href="source/drivers/cpufreq/cpufreq.c#L459">459</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=__cpufreq_set_policy">__cpufreq_set_policy</a>(policy, &amp;new_policy);
<a name="L460" href="source/drivers/cpufreq/cpufreq.c#L460">460</a> 
<a name="L461" href="source/drivers/cpufreq/cpufreq.c#L461">461</a>         policy-&gt;user_policy.policy = policy-&gt;policy;
<a name="L462" href="source/drivers/cpufreq/cpufreq.c#L462">462</a>         policy-&gt;user_policy.governor = policy-&gt;governor;
<a name="L463" href="source/drivers/cpufreq/cpufreq.c#L463">463</a> 
<a name="L464" href="source/drivers/cpufreq/cpufreq.c#L464">464</a>         if (<a href="ident?i=ret">ret</a>)
<a name="L465" href="source/drivers/cpufreq/cpufreq.c#L465">465</a>                 return <a href="ident?i=ret">ret</a>;
<a name="L466" href="source/drivers/cpufreq/cpufreq.c#L466">466</a>         else
<a name="L467" href="source/drivers/cpufreq/cpufreq.c#L467">467</a>                 return <a href="ident?i=count">count</a>;
<a name="L468" href="source/drivers/cpufreq/cpufreq.c#L468">468</a> }
<a name="L469" href="source/drivers/cpufreq/cpufreq.c#L469">469</a> 
<a name="L470" href="source/drivers/cpufreq/cpufreq.c#L470">470</a> <b><i>/**</i></b>
<a name="L471" href="source/drivers/cpufreq/cpufreq.c#L471">471</a> <b><i> * show_scaling_driver - show the cpufreq driver currently loaded</i></b>
<a name="L472" href="source/drivers/cpufreq/cpufreq.c#L472">472</a> <b><i> */</i></b>
<a name="L473" href="source/drivers/cpufreq/cpufreq.c#L473">473</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=show_scaling_driver">show_scaling_driver</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy, char *<a href="ident?i=buf">buf</a>)
<a name="L474" href="source/drivers/cpufreq/cpufreq.c#L474">474</a> {
<a name="L475" href="source/drivers/cpufreq/cpufreq.c#L475">475</a>         return <a href="ident?i=scnprintf">scnprintf</a>(<a href="ident?i=buf">buf</a>, <a href="ident?i=CPUFREQ_NAME_LEN">CPUFREQ_NAME_LEN</a>, <i>"%s\n"</i>, <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=name">name</a>);
<a name="L476" href="source/drivers/cpufreq/cpufreq.c#L476">476</a> }
<a name="L477" href="source/drivers/cpufreq/cpufreq.c#L477">477</a> 
<a name="L478" href="source/drivers/cpufreq/cpufreq.c#L478">478</a> <b><i>/**</i></b>
<a name="L479" href="source/drivers/cpufreq/cpufreq.c#L479">479</a> <b><i> * show_scaling_available_governors - show the available CPUfreq governors</i></b>
<a name="L480" href="source/drivers/cpufreq/cpufreq.c#L480">480</a> <b><i> */</i></b>
<a name="L481" href="source/drivers/cpufreq/cpufreq.c#L481">481</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=show_scaling_available_governors">show_scaling_available_governors</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy,
<a name="L482" href="source/drivers/cpufreq/cpufreq.c#L482">482</a>                                                 char *<a href="ident?i=buf">buf</a>)
<a name="L483" href="source/drivers/cpufreq/cpufreq.c#L483">483</a> {
<a name="L484" href="source/drivers/cpufreq/cpufreq.c#L484">484</a>         <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=i">i</a> = 0;
<a name="L485" href="source/drivers/cpufreq/cpufreq.c#L485">485</a>         struct <a href="ident?i=cpufreq_governor">cpufreq_governor</a> *<a href="ident?i=t">t</a>;
<a name="L486" href="source/drivers/cpufreq/cpufreq.c#L486">486</a> 
<a name="L487" href="source/drivers/cpufreq/cpufreq.c#L487">487</a>         if (!<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=target">target</a>) {
<a name="L488" href="source/drivers/cpufreq/cpufreq.c#L488">488</a>                 <a href="ident?i=i">i</a> += <a href="ident?i=sprintf">sprintf</a>(<a href="ident?i=buf">buf</a>, <i>"performance powersave"</i>);
<a name="L489" href="source/drivers/cpufreq/cpufreq.c#L489">489</a>                 goto <a href="ident?i=out">out</a>;
<a name="L490" href="source/drivers/cpufreq/cpufreq.c#L490">490</a>         }
<a name="L491" href="source/drivers/cpufreq/cpufreq.c#L491">491</a> 
<a name="L492" href="source/drivers/cpufreq/cpufreq.c#L492">492</a>         <a href="ident?i=list_for_each_entry">list_for_each_entry</a>(<a href="ident?i=t">t</a>, &amp;cpufreq_governor_list, governor_list) {
<a name="L493" href="source/drivers/cpufreq/cpufreq.c#L493">493</a>                 if (<a href="ident?i=i">i</a> &gt;= (<a href="ident?i=ssize_t">ssize_t</a>) ((<a href="ident?i=PAGE_SIZE">PAGE_SIZE</a> / sizeof(char))
<a name="L494" href="source/drivers/cpufreq/cpufreq.c#L494">494</a>                     - (<a href="ident?i=CPUFREQ_NAME_LEN">CPUFREQ_NAME_LEN</a> + 2)))
<a name="L495" href="source/drivers/cpufreq/cpufreq.c#L495">495</a>                         goto <a href="ident?i=out">out</a>;
<a name="L496" href="source/drivers/cpufreq/cpufreq.c#L496">496</a>                 <a href="ident?i=i">i</a> += <a href="ident?i=scnprintf">scnprintf</a>(&amp;<a href="ident?i=buf">buf</a>[<a href="ident?i=i">i</a>], <a href="ident?i=CPUFREQ_NAME_LEN">CPUFREQ_NAME_LEN</a>, <i>"%s "</i>, <a href="ident?i=t">t</a>-&gt;<a href="ident?i=name">name</a>);
<a name="L497" href="source/drivers/cpufreq/cpufreq.c#L497">497</a>         }
<a name="L498" href="source/drivers/cpufreq/cpufreq.c#L498">498</a> <a href="ident?i=out">out</a>:
<a name="L499" href="source/drivers/cpufreq/cpufreq.c#L499">499</a>         <a href="ident?i=i">i</a> += <a href="ident?i=sprintf">sprintf</a>(&amp;<a href="ident?i=buf">buf</a>[<a href="ident?i=i">i</a>], <i>"\n"</i>);
<a name="L500" href="source/drivers/cpufreq/cpufreq.c#L500">500</a>         return <a href="ident?i=i">i</a>;
<a name="L501" href="source/drivers/cpufreq/cpufreq.c#L501">501</a> }
<a name="L502" href="source/drivers/cpufreq/cpufreq.c#L502">502</a> 
<a name="L503" href="source/drivers/cpufreq/cpufreq.c#L503">503</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=show_cpus">show_cpus</a>(const struct <a href="ident?i=cpumask">cpumask</a> *<a href="ident?i=mask">mask</a>, char *<a href="ident?i=buf">buf</a>)
<a name="L504" href="source/drivers/cpufreq/cpufreq.c#L504">504</a> {
<a name="L505" href="source/drivers/cpufreq/cpufreq.c#L505">505</a>         <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=i">i</a> = 0;
<a name="L506" href="source/drivers/cpufreq/cpufreq.c#L506">506</a>         unsigned int <a href="ident?i=cpu">cpu</a>;
<a name="L507" href="source/drivers/cpufreq/cpufreq.c#L507">507</a> 
<a name="L508" href="source/drivers/cpufreq/cpufreq.c#L508">508</a>         <a href="ident?i=for_each_cpu">for_each_cpu</a>(<a href="ident?i=cpu">cpu</a>, <a href="ident?i=mask">mask</a>) {
<a name="L509" href="source/drivers/cpufreq/cpufreq.c#L509">509</a>                 if (<a href="ident?i=i">i</a>)
<a name="L510" href="source/drivers/cpufreq/cpufreq.c#L510">510</a>                         <a href="ident?i=i">i</a> += <a href="ident?i=scnprintf">scnprintf</a>(&amp;<a href="ident?i=buf">buf</a>[<a href="ident?i=i">i</a>], (<a href="ident?i=PAGE_SIZE">PAGE_SIZE</a> - <a href="ident?i=i">i</a> - 2), <i>" "</i>);
<a name="L511" href="source/drivers/cpufreq/cpufreq.c#L511">511</a>                 <a href="ident?i=i">i</a> += <a href="ident?i=scnprintf">scnprintf</a>(&amp;<a href="ident?i=buf">buf</a>[<a href="ident?i=i">i</a>], (<a href="ident?i=PAGE_SIZE">PAGE_SIZE</a> - <a href="ident?i=i">i</a> - 2), <i>"%u"</i>, <a href="ident?i=cpu">cpu</a>);
<a name="L512" href="source/drivers/cpufreq/cpufreq.c#L512">512</a>                 if (<a href="ident?i=i">i</a> &gt;= (<a href="ident?i=PAGE_SIZE">PAGE_SIZE</a> - 5))
<a name="L513" href="source/drivers/cpufreq/cpufreq.c#L513">513</a>                         break;
<a name="L514" href="source/drivers/cpufreq/cpufreq.c#L514">514</a>         }
<a name="L515" href="source/drivers/cpufreq/cpufreq.c#L515">515</a>         <a href="ident?i=i">i</a> += <a href="ident?i=sprintf">sprintf</a>(&amp;<a href="ident?i=buf">buf</a>[<a href="ident?i=i">i</a>], <i>"\n"</i>);
<a name="L516" href="source/drivers/cpufreq/cpufreq.c#L516">516</a>         return <a href="ident?i=i">i</a>;
<a name="L517" href="source/drivers/cpufreq/cpufreq.c#L517">517</a> }
<a name="L518" href="source/drivers/cpufreq/cpufreq.c#L518">518</a> 
<a name="L519" href="source/drivers/cpufreq/cpufreq.c#L519">519</a> <b><i>/**</i></b>
<a name="L520" href="source/drivers/cpufreq/cpufreq.c#L520">520</a> <b><i> * show_related_cpus - show the CPUs affected by each transition even if</i></b>
<a name="L521" href="source/drivers/cpufreq/cpufreq.c#L521">521</a> <b><i> * hw coordination is in use</i></b>
<a name="L522" href="source/drivers/cpufreq/cpufreq.c#L522">522</a> <b><i> */</i></b>
<a name="L523" href="source/drivers/cpufreq/cpufreq.c#L523">523</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=show_related_cpus">show_related_cpus</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy, char *<a href="ident?i=buf">buf</a>)
<a name="L524" href="source/drivers/cpufreq/cpufreq.c#L524">524</a> {
<a name="L525" href="source/drivers/cpufreq/cpufreq.c#L525">525</a>         if (<a href="ident?i=cpumask_empty">cpumask_empty</a>(policy-&gt;related_cpus))
<a name="L526" href="source/drivers/cpufreq/cpufreq.c#L526">526</a>                 return <a href="ident?i=show_cpus">show_cpus</a>(policy-&gt;cpus, <a href="ident?i=buf">buf</a>);
<a name="L527" href="source/drivers/cpufreq/cpufreq.c#L527">527</a>         return <a href="ident?i=show_cpus">show_cpus</a>(policy-&gt;related_cpus, <a href="ident?i=buf">buf</a>);
<a name="L528" href="source/drivers/cpufreq/cpufreq.c#L528">528</a> }
<a name="L529" href="source/drivers/cpufreq/cpufreq.c#L529">529</a> 
<a name="L530" href="source/drivers/cpufreq/cpufreq.c#L530">530</a> <b><i>/**</i></b>
<a name="L531" href="source/drivers/cpufreq/cpufreq.c#L531">531</a> <b><i> * show_affected_cpus - show the CPUs affected by each transition</i></b>
<a name="L532" href="source/drivers/cpufreq/cpufreq.c#L532">532</a> <b><i> */</i></b>
<a name="L533" href="source/drivers/cpufreq/cpufreq.c#L533">533</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=show_affected_cpus">show_affected_cpus</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy, char *<a href="ident?i=buf">buf</a>)
<a name="L534" href="source/drivers/cpufreq/cpufreq.c#L534">534</a> {
<a name="L535" href="source/drivers/cpufreq/cpufreq.c#L535">535</a>         return <a href="ident?i=show_cpus">show_cpus</a>(policy-&gt;cpus, <a href="ident?i=buf">buf</a>);
<a name="L536" href="source/drivers/cpufreq/cpufreq.c#L536">536</a> }
<a name="L537" href="source/drivers/cpufreq/cpufreq.c#L537">537</a> 
<a name="L538" href="source/drivers/cpufreq/cpufreq.c#L538">538</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=store_scaling_setspeed">store_scaling_setspeed</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy,
<a name="L539" href="source/drivers/cpufreq/cpufreq.c#L539">539</a>                                         const char *<a href="ident?i=buf">buf</a>, <a href="ident?i=size_t">size_t</a> <a href="ident?i=count">count</a>)
<a name="L540" href="source/drivers/cpufreq/cpufreq.c#L540">540</a> {
<a name="L541" href="source/drivers/cpufreq/cpufreq.c#L541">541</a>         unsigned int <a href="ident?i=freq">freq</a> = 0;
<a name="L542" href="source/drivers/cpufreq/cpufreq.c#L542">542</a>         unsigned int <a href="ident?i=ret">ret</a>;
<a name="L543" href="source/drivers/cpufreq/cpufreq.c#L543">543</a> 
<a name="L544" href="source/drivers/cpufreq/cpufreq.c#L544">544</a>         if (!policy-&gt;governor || !policy-&gt;governor-&gt;store_setspeed)
<a name="L545" href="source/drivers/cpufreq/cpufreq.c#L545">545</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L546" href="source/drivers/cpufreq/cpufreq.c#L546">546</a> 
<a name="L547" href="source/drivers/cpufreq/cpufreq.c#L547">547</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=sscanf">sscanf</a>(<a href="ident?i=buf">buf</a>, <i>"%u"</i>, &amp;<a href="ident?i=freq">freq</a>);
<a name="L548" href="source/drivers/cpufreq/cpufreq.c#L548">548</a>         if (<a href="ident?i=ret">ret</a> != 1)
<a name="L549" href="source/drivers/cpufreq/cpufreq.c#L549">549</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L550" href="source/drivers/cpufreq/cpufreq.c#L550">550</a> 
<a name="L551" href="source/drivers/cpufreq/cpufreq.c#L551">551</a>         policy-&gt;governor-&gt;store_setspeed(policy, <a href="ident?i=freq">freq</a>);
<a name="L552" href="source/drivers/cpufreq/cpufreq.c#L552">552</a> 
<a name="L553" href="source/drivers/cpufreq/cpufreq.c#L553">553</a>         return <a href="ident?i=count">count</a>;
<a name="L554" href="source/drivers/cpufreq/cpufreq.c#L554">554</a> }
<a name="L555" href="source/drivers/cpufreq/cpufreq.c#L555">555</a> 
<a name="L556" href="source/drivers/cpufreq/cpufreq.c#L556">556</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=show_scaling_setspeed">show_scaling_setspeed</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy, char *<a href="ident?i=buf">buf</a>)
<a name="L557" href="source/drivers/cpufreq/cpufreq.c#L557">557</a> {
<a name="L558" href="source/drivers/cpufreq/cpufreq.c#L558">558</a>         if (!policy-&gt;governor || !policy-&gt;governor-&gt;show_setspeed)
<a name="L559" href="source/drivers/cpufreq/cpufreq.c#L559">559</a>                 return <a href="ident?i=sprintf">sprintf</a>(<a href="ident?i=buf">buf</a>, <i>"&lt;unsupported&gt;\n"</i>);
<a name="L560" href="source/drivers/cpufreq/cpufreq.c#L560">560</a> 
<a name="L561" href="source/drivers/cpufreq/cpufreq.c#L561">561</a>         return policy-&gt;governor-&gt;show_setspeed(policy, <a href="ident?i=buf">buf</a>);
<a name="L562" href="source/drivers/cpufreq/cpufreq.c#L562">562</a> }
<a name="L563" href="source/drivers/cpufreq/cpufreq.c#L563">563</a> 
<a name="L564" href="source/drivers/cpufreq/cpufreq.c#L564">564</a> <b><i>/**</i></b>
<a name="L565" href="source/drivers/cpufreq/cpufreq.c#L565">565</a> <b><i> * show_scaling_driver - show the current cpufreq HW/BIOS limitation</i></b>
<a name="L566" href="source/drivers/cpufreq/cpufreq.c#L566">566</a> <b><i> */</i></b>
<a name="L567" href="source/drivers/cpufreq/cpufreq.c#L567">567</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=show_bios_limit">show_bios_limit</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy, char *<a href="ident?i=buf">buf</a>)
<a name="L568" href="source/drivers/cpufreq/cpufreq.c#L568">568</a> {
<a name="L569" href="source/drivers/cpufreq/cpufreq.c#L569">569</a>         unsigned int <a href="ident?i=limit">limit</a>;
<a name="L570" href="source/drivers/cpufreq/cpufreq.c#L570">570</a>         int <a href="ident?i=ret">ret</a>;
<a name="L571" href="source/drivers/cpufreq/cpufreq.c#L571">571</a>         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;bios_limit) {
<a name="L572" href="source/drivers/cpufreq/cpufreq.c#L572">572</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;bios_limit(policy-&gt;<a href="ident?i=cpu">cpu</a>, &amp;<a href="ident?i=limit">limit</a>);
<a name="L573" href="source/drivers/cpufreq/cpufreq.c#L573">573</a>                 if (!<a href="ident?i=ret">ret</a>)
<a name="L574" href="source/drivers/cpufreq/cpufreq.c#L574">574</a>                         return <a href="ident?i=sprintf">sprintf</a>(<a href="ident?i=buf">buf</a>, <i>"%u\n"</i>, <a href="ident?i=limit">limit</a>);
<a name="L575" href="source/drivers/cpufreq/cpufreq.c#L575">575</a>         }
<a name="L576" href="source/drivers/cpufreq/cpufreq.c#L576">576</a>         return <a href="ident?i=sprintf">sprintf</a>(<a href="ident?i=buf">buf</a>, <i>"%u\n"</i>, policy-&gt;<a href="ident?i=cpuinfo">cpuinfo</a>.<a href="ident?i=max_freq">max_freq</a>);
<a name="L577" href="source/drivers/cpufreq/cpufreq.c#L577">577</a> }
<a name="L578" href="source/drivers/cpufreq/cpufreq.c#L578">578</a> 
<a name="L579" href="source/drivers/cpufreq/cpufreq.c#L579">579</a> <a href="ident?i=cpufreq_freq_attr_ro_perm">cpufreq_freq_attr_ro_perm</a>(cpuinfo_cur_freq, 0400);
<a name="L580" href="source/drivers/cpufreq/cpufreq.c#L580">580</a> <a href="ident?i=cpufreq_freq_attr_ro">cpufreq_freq_attr_ro</a>(cpuinfo_min_freq);
<a name="L581" href="source/drivers/cpufreq/cpufreq.c#L581">581</a> <a href="ident?i=cpufreq_freq_attr_ro">cpufreq_freq_attr_ro</a>(cpuinfo_max_freq);
<a name="L582" href="source/drivers/cpufreq/cpufreq.c#L582">582</a> <a href="ident?i=cpufreq_freq_attr_ro">cpufreq_freq_attr_ro</a>(cpuinfo_transition_latency);
<a name="L583" href="source/drivers/cpufreq/cpufreq.c#L583">583</a> <a href="ident?i=cpufreq_freq_attr_ro">cpufreq_freq_attr_ro</a>(scaling_available_governors);
<a name="L584" href="source/drivers/cpufreq/cpufreq.c#L584">584</a> <a href="ident?i=cpufreq_freq_attr_ro">cpufreq_freq_attr_ro</a>(scaling_driver);
<a name="L585" href="source/drivers/cpufreq/cpufreq.c#L585">585</a> <a href="ident?i=cpufreq_freq_attr_ro">cpufreq_freq_attr_ro</a>(scaling_cur_freq);
<a name="L586" href="source/drivers/cpufreq/cpufreq.c#L586">586</a> <a href="ident?i=cpufreq_freq_attr_ro">cpufreq_freq_attr_ro</a>(bios_limit);
<a name="L587" href="source/drivers/cpufreq/cpufreq.c#L587">587</a> <a href="ident?i=cpufreq_freq_attr_ro">cpufreq_freq_attr_ro</a>(related_cpus);
<a name="L588" href="source/drivers/cpufreq/cpufreq.c#L588">588</a> <a href="ident?i=cpufreq_freq_attr_ro">cpufreq_freq_attr_ro</a>(affected_cpus);
<a name="L589" href="source/drivers/cpufreq/cpufreq.c#L589">589</a> <a href="ident?i=cpufreq_freq_attr_rw">cpufreq_freq_attr_rw</a>(scaling_min_freq);
<a name="L590" href="source/drivers/cpufreq/cpufreq.c#L590">590</a> <a href="ident?i=cpufreq_freq_attr_rw">cpufreq_freq_attr_rw</a>(scaling_max_freq);
<a name="L591" href="source/drivers/cpufreq/cpufreq.c#L591">591</a> <a href="ident?i=cpufreq_freq_attr_rw">cpufreq_freq_attr_rw</a>(scaling_governor);
<a name="L592" href="source/drivers/cpufreq/cpufreq.c#L592">592</a> <a href="ident?i=cpufreq_freq_attr_rw">cpufreq_freq_attr_rw</a>(scaling_setspeed);
<a name="L593" href="source/drivers/cpufreq/cpufreq.c#L593">593</a> 
<a name="L594" href="source/drivers/cpufreq/cpufreq.c#L594">594</a> static struct <a href="ident?i=attribute">attribute</a> *<a href="ident?i=default_attrs">default_attrs</a>[] = {
<a name="L595" href="source/drivers/cpufreq/cpufreq.c#L595">595</a>         &amp;cpuinfo_min_freq.<a href="ident?i=attr">attr</a>,
<a name="L596" href="source/drivers/cpufreq/cpufreq.c#L596">596</a>         &amp;cpuinfo_max_freq.<a href="ident?i=attr">attr</a>,
<a name="L597" href="source/drivers/cpufreq/cpufreq.c#L597">597</a>         &amp;cpuinfo_transition_latency.<a href="ident?i=attr">attr</a>,
<a name="L598" href="source/drivers/cpufreq/cpufreq.c#L598">598</a>         &amp;scaling_min_freq.<a href="ident?i=attr">attr</a>,
<a name="L599" href="source/drivers/cpufreq/cpufreq.c#L599">599</a>         &amp;scaling_max_freq.<a href="ident?i=attr">attr</a>,
<a name="L600" href="source/drivers/cpufreq/cpufreq.c#L600">600</a>         &amp;affected_cpus.<a href="ident?i=attr">attr</a>,
<a name="L601" href="source/drivers/cpufreq/cpufreq.c#L601">601</a>         &amp;related_cpus.<a href="ident?i=attr">attr</a>,
<a name="L602" href="source/drivers/cpufreq/cpufreq.c#L602">602</a>         &amp;scaling_governor.<a href="ident?i=attr">attr</a>,
<a name="L603" href="source/drivers/cpufreq/cpufreq.c#L603">603</a>         &amp;scaling_driver.<a href="ident?i=attr">attr</a>,
<a name="L604" href="source/drivers/cpufreq/cpufreq.c#L604">604</a>         &amp;scaling_available_governors.<a href="ident?i=attr">attr</a>,
<a name="L605" href="source/drivers/cpufreq/cpufreq.c#L605">605</a>         &amp;scaling_setspeed.<a href="ident?i=attr">attr</a>,
<a name="L606" href="source/drivers/cpufreq/cpufreq.c#L606">606</a>         <a href="ident?i=NULL">NULL</a>
<a name="L607" href="source/drivers/cpufreq/cpufreq.c#L607">607</a> };
<a name="L608" href="source/drivers/cpufreq/cpufreq.c#L608">608</a> 
<a name="L609" href="source/drivers/cpufreq/cpufreq.c#L609">609</a> struct <a href="ident?i=kobject">kobject</a> *<a href="ident?i=cpufreq_global_kobject">cpufreq_global_kobject</a>;
<a name="L610" href="source/drivers/cpufreq/cpufreq.c#L610">610</a> <a href="ident?i=EXPORT_SYMBOL">EXPORT_SYMBOL</a>(<a href="ident?i=cpufreq_global_kobject">cpufreq_global_kobject</a>);
<a name="L611" href="source/drivers/cpufreq/cpufreq.c#L611">611</a> 
<a name="L612" href="source/drivers/cpufreq/cpufreq.c#L612">612</a> #define <a href="ident?i=to_policy">to_policy</a>(k) <a href="ident?i=container_of">container_of</a>(k, struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a>, <a href="ident?i=kobj">kobj</a>)
<a name="L613" href="source/drivers/cpufreq/cpufreq.c#L613">613</a> #define <a href="ident?i=to_attr">to_attr</a>(<a href="ident?i=a">a</a>) <a href="ident?i=container_of">container_of</a>(<a href="ident?i=a">a</a>, struct <a href="ident?i=freq_attr">freq_attr</a>, <a href="ident?i=attr">attr</a>)
<a name="L614" href="source/drivers/cpufreq/cpufreq.c#L614">614</a> 
<a name="L615" href="source/drivers/cpufreq/cpufreq.c#L615">615</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=show">show</a>(struct <a href="ident?i=kobject">kobject</a> *<a href="ident?i=kobj">kobj</a>, struct <a href="ident?i=attribute">attribute</a> *<a href="ident?i=attr">attr</a>, char *<a href="ident?i=buf">buf</a>)
<a name="L616" href="source/drivers/cpufreq/cpufreq.c#L616">616</a> {
<a name="L617" href="source/drivers/cpufreq/cpufreq.c#L617">617</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy = <a href="ident?i=to_policy">to_policy</a>(<a href="ident?i=kobj">kobj</a>);
<a name="L618" href="source/drivers/cpufreq/cpufreq.c#L618">618</a>         struct <a href="ident?i=freq_attr">freq_attr</a> *fattr = <a href="ident?i=to_attr">to_attr</a>(<a href="ident?i=attr">attr</a>);
<a name="L619" href="source/drivers/cpufreq/cpufreq.c#L619">619</a>         <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=ret">ret</a> = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L620" href="source/drivers/cpufreq/cpufreq.c#L620">620</a>         policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(policy-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L621" href="source/drivers/cpufreq/cpufreq.c#L621">621</a>         if (!policy)
<a name="L622" href="source/drivers/cpufreq/cpufreq.c#L622">622</a>                 goto no_policy;
<a name="L623" href="source/drivers/cpufreq/cpufreq.c#L623">623</a> 
<a name="L624" href="source/drivers/cpufreq/cpufreq.c#L624">624</a>         if (lock_policy_rwsem_read(policy-&gt;<a href="ident?i=cpu">cpu</a>) &lt; 0)
<a name="L625" href="source/drivers/cpufreq/cpufreq.c#L625">625</a>                 goto fail;
<a name="L626" href="source/drivers/cpufreq/cpufreq.c#L626">626</a> 
<a name="L627" href="source/drivers/cpufreq/cpufreq.c#L627">627</a>         if (fattr-&gt;<a href="ident?i=show">show</a>)
<a name="L628" href="source/drivers/cpufreq/cpufreq.c#L628">628</a>                 <a href="ident?i=ret">ret</a> = fattr-&gt;<a href="ident?i=show">show</a>(policy, <a href="ident?i=buf">buf</a>);
<a name="L629" href="source/drivers/cpufreq/cpufreq.c#L629">629</a>         else
<a name="L630" href="source/drivers/cpufreq/cpufreq.c#L630">630</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=EIO">EIO</a>;
<a name="L631" href="source/drivers/cpufreq/cpufreq.c#L631">631</a> 
<a name="L632" href="source/drivers/cpufreq/cpufreq.c#L632">632</a>         <a href="ident?i=unlock_policy_rwsem_read">unlock_policy_rwsem_read</a>(policy-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L633" href="source/drivers/cpufreq/cpufreq.c#L633">633</a> fail:
<a name="L634" href="source/drivers/cpufreq/cpufreq.c#L634">634</a>         <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(policy);
<a name="L635" href="source/drivers/cpufreq/cpufreq.c#L635">635</a> no_policy:
<a name="L636" href="source/drivers/cpufreq/cpufreq.c#L636">636</a>         return <a href="ident?i=ret">ret</a>;
<a name="L637" href="source/drivers/cpufreq/cpufreq.c#L637">637</a> }
<a name="L638" href="source/drivers/cpufreq/cpufreq.c#L638">638</a> 
<a name="L639" href="source/drivers/cpufreq/cpufreq.c#L639">639</a> static <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=store">store</a>(struct <a href="ident?i=kobject">kobject</a> *<a href="ident?i=kobj">kobj</a>, struct <a href="ident?i=attribute">attribute</a> *<a href="ident?i=attr">attr</a>,
<a name="L640" href="source/drivers/cpufreq/cpufreq.c#L640">640</a>                      const char *<a href="ident?i=buf">buf</a>, <a href="ident?i=size_t">size_t</a> <a href="ident?i=count">count</a>)
<a name="L641" href="source/drivers/cpufreq/cpufreq.c#L641">641</a> {
<a name="L642" href="source/drivers/cpufreq/cpufreq.c#L642">642</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy = <a href="ident?i=to_policy">to_policy</a>(<a href="ident?i=kobj">kobj</a>);
<a name="L643" href="source/drivers/cpufreq/cpufreq.c#L643">643</a>         struct <a href="ident?i=freq_attr">freq_attr</a> *fattr = <a href="ident?i=to_attr">to_attr</a>(<a href="ident?i=attr">attr</a>);
<a name="L644" href="source/drivers/cpufreq/cpufreq.c#L644">644</a>         <a href="ident?i=ssize_t">ssize_t</a> <a href="ident?i=ret">ret</a> = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L645" href="source/drivers/cpufreq/cpufreq.c#L645">645</a>         policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(policy-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L646" href="source/drivers/cpufreq/cpufreq.c#L646">646</a>         if (!policy)
<a name="L647" href="source/drivers/cpufreq/cpufreq.c#L647">647</a>                 goto no_policy;
<a name="L648" href="source/drivers/cpufreq/cpufreq.c#L648">648</a> 
<a name="L649" href="source/drivers/cpufreq/cpufreq.c#L649">649</a>         if (lock_policy_rwsem_write(policy-&gt;<a href="ident?i=cpu">cpu</a>) &lt; 0)
<a name="L650" href="source/drivers/cpufreq/cpufreq.c#L650">650</a>                 goto fail;
<a name="L651" href="source/drivers/cpufreq/cpufreq.c#L651">651</a> 
<a name="L652" href="source/drivers/cpufreq/cpufreq.c#L652">652</a>         if (fattr-&gt;<a href="ident?i=store">store</a>)
<a name="L653" href="source/drivers/cpufreq/cpufreq.c#L653">653</a>                 <a href="ident?i=ret">ret</a> = fattr-&gt;<a href="ident?i=store">store</a>(policy, <a href="ident?i=buf">buf</a>, <a href="ident?i=count">count</a>);
<a name="L654" href="source/drivers/cpufreq/cpufreq.c#L654">654</a>         else
<a name="L655" href="source/drivers/cpufreq/cpufreq.c#L655">655</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=EIO">EIO</a>;
<a name="L656" href="source/drivers/cpufreq/cpufreq.c#L656">656</a> 
<a name="L657" href="source/drivers/cpufreq/cpufreq.c#L657">657</a>         <a href="ident?i=unlock_policy_rwsem_write">unlock_policy_rwsem_write</a>(policy-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L658" href="source/drivers/cpufreq/cpufreq.c#L658">658</a> fail:
<a name="L659" href="source/drivers/cpufreq/cpufreq.c#L659">659</a>         <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(policy);
<a name="L660" href="source/drivers/cpufreq/cpufreq.c#L660">660</a> no_policy:
<a name="L661" href="source/drivers/cpufreq/cpufreq.c#L661">661</a>         return <a href="ident?i=ret">ret</a>;
<a name="L662" href="source/drivers/cpufreq/cpufreq.c#L662">662</a> }
<a name="L663" href="source/drivers/cpufreq/cpufreq.c#L663">663</a> 
<a name="L664" href="source/drivers/cpufreq/cpufreq.c#L664">664</a> static void <a href="ident?i=cpufreq_sysfs_release">cpufreq_sysfs_release</a>(struct <a href="ident?i=kobject">kobject</a> *<a href="ident?i=kobj">kobj</a>)
<a name="L665" href="source/drivers/cpufreq/cpufreq.c#L665">665</a> {
<a name="L666" href="source/drivers/cpufreq/cpufreq.c#L666">666</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy = <a href="ident?i=to_policy">to_policy</a>(<a href="ident?i=kobj">kobj</a>);
<a name="L667" href="source/drivers/cpufreq/cpufreq.c#L667">667</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"last reference is dropped\n"</i>);
<a name="L668" href="source/drivers/cpufreq/cpufreq.c#L668">668</a>         <a href="ident?i=complete">complete</a>(&amp;policy-&gt;kobj_unregister);
<a name="L669" href="source/drivers/cpufreq/cpufreq.c#L669">669</a> }
<a name="L670" href="source/drivers/cpufreq/cpufreq.c#L670">670</a> 
<a name="L671" href="source/drivers/cpufreq/cpufreq.c#L671">671</a> static const struct <a href="ident?i=sysfs_ops">sysfs_ops</a> <a href="ident?i=sysfs_ops">sysfs_ops</a> = {
<a name="L672" href="source/drivers/cpufreq/cpufreq.c#L672">672</a>         .<a href="ident?i=show">show</a>   = <a href="ident?i=show">show</a>,
<a name="L673" href="source/drivers/cpufreq/cpufreq.c#L673">673</a>         .<a href="ident?i=store">store</a>  = <a href="ident?i=store">store</a>,
<a name="L674" href="source/drivers/cpufreq/cpufreq.c#L674">674</a> };
<a name="L675" href="source/drivers/cpufreq/cpufreq.c#L675">675</a> 
<a name="L676" href="source/drivers/cpufreq/cpufreq.c#L676">676</a> static struct <a href="ident?i=kobj_type">kobj_type</a> <a href="ident?i=ktype_cpufreq">ktype_cpufreq</a> = {
<a name="L677" href="source/drivers/cpufreq/cpufreq.c#L677">677</a>         .<a href="ident?i=sysfs_ops">sysfs_ops</a>      = &amp;<a href="ident?i=sysfs_ops">sysfs_ops</a>,
<a name="L678" href="source/drivers/cpufreq/cpufreq.c#L678">678</a>         .<a href="ident?i=default_attrs">default_attrs</a>  = <a href="ident?i=default_attrs">default_attrs</a>,
<a name="L679" href="source/drivers/cpufreq/cpufreq.c#L679">679</a>         .<a href="ident?i=release">release</a>        = <a href="ident?i=cpufreq_sysfs_release">cpufreq_sysfs_release</a>,
<a name="L680" href="source/drivers/cpufreq/cpufreq.c#L680">680</a> };
<a name="L681" href="source/drivers/cpufreq/cpufreq.c#L681">681</a> 
<a name="L682" href="source/drivers/cpufreq/cpufreq.c#L682">682</a> <b><i>/*</i></b>
<a name="L683" href="source/drivers/cpufreq/cpufreq.c#L683">683</a> <b><i> * Returns:</i></b>
<a name="L684" href="source/drivers/cpufreq/cpufreq.c#L684">684</a> <b><i> *   Negative: Failure</i></b>
<a name="L685" href="source/drivers/cpufreq/cpufreq.c#L685">685</a> <b><i> *   0:        Success</i></b>
<a name="L686" href="source/drivers/cpufreq/cpufreq.c#L686">686</a> <b><i> *   Positive: When we have a managed CPU and the sysfs got symlinked</i></b>
<a name="L687" href="source/drivers/cpufreq/cpufreq.c#L687">687</a> <b><i> */</i></b>
<a name="L688" href="source/drivers/cpufreq/cpufreq.c#L688">688</a> static int <a href="ident?i=cpufreq_add_dev_policy">cpufreq_add_dev_policy</a>(unsigned int <a href="ident?i=cpu">cpu</a>,
<a name="L689" href="source/drivers/cpufreq/cpufreq.c#L689">689</a>                                   struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy,
<a name="L690" href="source/drivers/cpufreq/cpufreq.c#L690">690</a>                                   struct <a href="ident?i=device">device</a> *<a href="ident?i=dev">dev</a>)
<a name="L691" href="source/drivers/cpufreq/cpufreq.c#L691">691</a> {
<a name="L692" href="source/drivers/cpufreq/cpufreq.c#L692">692</a>         int <a href="ident?i=ret">ret</a> = 0;
<a name="L693" href="source/drivers/cpufreq/cpufreq.c#L693">693</a> #ifdef <a href="ident?i=CONFIG_SMP">CONFIG_SMP</a>
<a name="L694" href="source/drivers/cpufreq/cpufreq.c#L694">694</a>         unsigned long <a href="ident?i=flags">flags</a>;
<a name="L695" href="source/drivers/cpufreq/cpufreq.c#L695">695</a>         unsigned int j;
<a name="L696" href="source/drivers/cpufreq/cpufreq.c#L696">696</a> #ifdef CONFIG_HOTPLUG_CPU
<a name="L697" href="source/drivers/cpufreq/cpufreq.c#L697">697</a>         struct <a href="ident?i=cpufreq_governor">cpufreq_governor</a> *gov;
<a name="L698" href="source/drivers/cpufreq/cpufreq.c#L698">698</a> 
<a name="L699" href="source/drivers/cpufreq/cpufreq.c#L699">699</a>         gov = <a href="ident?i=__find_governor">__find_governor</a>(<a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_governor, <a href="ident?i=cpu">cpu</a>));
<a name="L700" href="source/drivers/cpufreq/cpufreq.c#L700">700</a>         if (gov) {
<a name="L701" href="source/drivers/cpufreq/cpufreq.c#L701">701</a>                 policy-&gt;governor = gov;
<a name="L702" href="source/drivers/cpufreq/cpufreq.c#L702">702</a>                 <a href="ident?i=pr_debug">pr_debug</a>(<i>"Restoring governor %s for cpu %d\n"</i>,
<a name="L703" href="source/drivers/cpufreq/cpufreq.c#L703">703</a>                        policy-&gt;governor-&gt;<a href="ident?i=name">name</a>, <a href="ident?i=cpu">cpu</a>);
<a name="L704" href="source/drivers/cpufreq/cpufreq.c#L704">704</a>         }
<a name="L705" href="source/drivers/cpufreq/cpufreq.c#L705">705</a> #endif
<a name="L706" href="source/drivers/cpufreq/cpufreq.c#L706">706</a> 
<a name="L707" href="source/drivers/cpufreq/cpufreq.c#L707">707</a>         <a href="ident?i=for_each_cpu">for_each_cpu</a>(j, policy-&gt;cpus) {
<a name="L708" href="source/drivers/cpufreq/cpufreq.c#L708">708</a>                 struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *managed_policy;
<a name="L709" href="source/drivers/cpufreq/cpufreq.c#L709">709</a> 
<a name="L710" href="source/drivers/cpufreq/cpufreq.c#L710">710</a>                 if (<a href="ident?i=cpu">cpu</a> == j)
<a name="L711" href="source/drivers/cpufreq/cpufreq.c#L711">711</a>                         continue;
<a name="L712" href="source/drivers/cpufreq/cpufreq.c#L712">712</a> 
<a name="L713" href="source/drivers/cpufreq/cpufreq.c#L713">713</a>                 <b><i>/* Check for existing affected CPUs.</i></b>
<a name="L714" href="source/drivers/cpufreq/cpufreq.c#L714">714</a> <b><i>                 * They may not be aware of it due to CPU Hotplug.</i></b>
<a name="L715" href="source/drivers/cpufreq/cpufreq.c#L715">715</a> <b><i>                 * cpufreq_cpu_put is called when the device is removed</i></b>
<a name="L716" href="source/drivers/cpufreq/cpufreq.c#L716">716</a> <b><i>                 * in __cpufreq_remove_dev()</i></b>
<a name="L717" href="source/drivers/cpufreq/cpufreq.c#L717">717</a> <b><i>                 */</i></b>
<a name="L718" href="source/drivers/cpufreq/cpufreq.c#L718">718</a>                 managed_policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(j);
<a name="L719" href="source/drivers/cpufreq/cpufreq.c#L719">719</a>                 if (<a href="ident?i=unlikely">unlikely</a>(managed_policy)) {
<a name="L720" href="source/drivers/cpufreq/cpufreq.c#L720">720</a> 
<a name="L721" href="source/drivers/cpufreq/cpufreq.c#L721">721</a>                         <b><i>/* Set proper policy_cpu */</i></b>
<a name="L722" href="source/drivers/cpufreq/cpufreq.c#L722">722</a>                         <a href="ident?i=unlock_policy_rwsem_write">unlock_policy_rwsem_write</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L723" href="source/drivers/cpufreq/cpufreq.c#L723">723</a>                         <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_policy_cpu, <a href="ident?i=cpu">cpu</a>) = managed_policy-&gt;<a href="ident?i=cpu">cpu</a>;
<a name="L724" href="source/drivers/cpufreq/cpufreq.c#L724">724</a> 
<a name="L725" href="source/drivers/cpufreq/cpufreq.c#L725">725</a>                         if (lock_policy_rwsem_write(<a href="ident?i=cpu">cpu</a>) &lt; 0) {
<a name="L726" href="source/drivers/cpufreq/cpufreq.c#L726">726</a>                                 <b><i>/* Should not go through policy unlock path */</i></b>
<a name="L727" href="source/drivers/cpufreq/cpufreq.c#L727">727</a>                                 if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=exit">exit</a>)
<a name="L728" href="source/drivers/cpufreq/cpufreq.c#L728">728</a>                                         <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=exit">exit</a>(policy);
<a name="L729" href="source/drivers/cpufreq/cpufreq.c#L729">729</a>                                 <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(managed_policy);
<a name="L730" href="source/drivers/cpufreq/cpufreq.c#L730">730</a>                                 return -<a href="ident?i=EBUSY">EBUSY</a>;
<a name="L731" href="source/drivers/cpufreq/cpufreq.c#L731">731</a>                         }
<a name="L732" href="source/drivers/cpufreq/cpufreq.c#L732">732</a> 
<a name="L733" href="source/drivers/cpufreq/cpufreq.c#L733">733</a>                         <a href="ident?i=spin_lock_irqsave">spin_lock_irqsave</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L734" href="source/drivers/cpufreq/cpufreq.c#L734">734</a>                         <a href="ident?i=cpumask_copy">cpumask_copy</a>(managed_policy-&gt;cpus, policy-&gt;cpus);
<a name="L735" href="source/drivers/cpufreq/cpufreq.c#L735">735</a>                         <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_data, <a href="ident?i=cpu">cpu</a>) = managed_policy;
<a name="L736" href="source/drivers/cpufreq/cpufreq.c#L736">736</a>                         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L737" href="source/drivers/cpufreq/cpufreq.c#L737">737</a> 
<a name="L738" href="source/drivers/cpufreq/cpufreq.c#L738">738</a>                         <a href="ident?i=pr_debug">pr_debug</a>(<i>"CPU already managed, adding link\n"</i>);
<a name="L739" href="source/drivers/cpufreq/cpufreq.c#L739">739</a>                         <a href="ident?i=ret">ret</a> = <a href="ident?i=sysfs_create_link">sysfs_create_link</a>(&amp;<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=kobj">kobj</a>,
<a name="L740" href="source/drivers/cpufreq/cpufreq.c#L740">740</a>                                                 &amp;managed_policy-&gt;<a href="ident?i=kobj">kobj</a>,
<a name="L741" href="source/drivers/cpufreq/cpufreq.c#L741">741</a>                                                 <i>"cpufreq"</i>);
<a name="L742" href="source/drivers/cpufreq/cpufreq.c#L742">742</a>                         if (<a href="ident?i=ret">ret</a>)
<a name="L743" href="source/drivers/cpufreq/cpufreq.c#L743">743</a>                                 <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(managed_policy);
<a name="L744" href="source/drivers/cpufreq/cpufreq.c#L744">744</a>                         <b><i>/*</i></b>
<a name="L745" href="source/drivers/cpufreq/cpufreq.c#L745">745</a> <b><i>                         * Success. We only needed to be added to the mask.</i></b>
<a name="L746" href="source/drivers/cpufreq/cpufreq.c#L746">746</a> <b><i>                         * Call driver-&gt;exit() because only the cpu parent of</i></b>
<a name="L747" href="source/drivers/cpufreq/cpufreq.c#L747">747</a> <b><i>                         * the kobj needed to call init().</i></b>
<a name="L748" href="source/drivers/cpufreq/cpufreq.c#L748">748</a> <b><i>                         */</i></b>
<a name="L749" href="source/drivers/cpufreq/cpufreq.c#L749">749</a>                         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=exit">exit</a>)
<a name="L750" href="source/drivers/cpufreq/cpufreq.c#L750">750</a>                                 <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=exit">exit</a>(policy);
<a name="L751" href="source/drivers/cpufreq/cpufreq.c#L751">751</a> 
<a name="L752" href="source/drivers/cpufreq/cpufreq.c#L752">752</a>                         if (!<a href="ident?i=ret">ret</a>)
<a name="L753" href="source/drivers/cpufreq/cpufreq.c#L753">753</a>                                 return 1;
<a name="L754" href="source/drivers/cpufreq/cpufreq.c#L754">754</a>                         else
<a name="L755" href="source/drivers/cpufreq/cpufreq.c#L755">755</a>                                 return <a href="ident?i=ret">ret</a>;
<a name="L756" href="source/drivers/cpufreq/cpufreq.c#L756">756</a>                 }
<a name="L757" href="source/drivers/cpufreq/cpufreq.c#L757">757</a>         }
<a name="L758" href="source/drivers/cpufreq/cpufreq.c#L758">758</a> #endif
<a name="L759" href="source/drivers/cpufreq/cpufreq.c#L759">759</a>         return <a href="ident?i=ret">ret</a>;
<a name="L760" href="source/drivers/cpufreq/cpufreq.c#L760">760</a> }
<a name="L761" href="source/drivers/cpufreq/cpufreq.c#L761">761</a> 
<a name="L762" href="source/drivers/cpufreq/cpufreq.c#L762">762</a> 
<a name="L763" href="source/drivers/cpufreq/cpufreq.c#L763">763</a> <b><i>/* symlink affected CPUs */</i></b>
<a name="L764" href="source/drivers/cpufreq/cpufreq.c#L764">764</a> static int <a href="ident?i=cpufreq_add_dev_symlink">cpufreq_add_dev_symlink</a>(unsigned int <a href="ident?i=cpu">cpu</a>,
<a name="L765" href="source/drivers/cpufreq/cpufreq.c#L765">765</a>                                    struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy)
<a name="L766" href="source/drivers/cpufreq/cpufreq.c#L766">766</a> {
<a name="L767" href="source/drivers/cpufreq/cpufreq.c#L767">767</a>         unsigned int j;
<a name="L768" href="source/drivers/cpufreq/cpufreq.c#L768">768</a>         int <a href="ident?i=ret">ret</a> = 0;
<a name="L769" href="source/drivers/cpufreq/cpufreq.c#L769">769</a> 
<a name="L770" href="source/drivers/cpufreq/cpufreq.c#L770">770</a>         <a href="ident?i=for_each_cpu">for_each_cpu</a>(j, policy-&gt;cpus) {
<a name="L771" href="source/drivers/cpufreq/cpufreq.c#L771">771</a>                 struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *managed_policy;
<a name="L772" href="source/drivers/cpufreq/cpufreq.c#L772">772</a>                 struct <a href="ident?i=device">device</a> *<a href="ident?i=cpu_dev">cpu_dev</a>;
<a name="L773" href="source/drivers/cpufreq/cpufreq.c#L773">773</a> 
<a name="L774" href="source/drivers/cpufreq/cpufreq.c#L774">774</a>                 if (j == <a href="ident?i=cpu">cpu</a>)
<a name="L775" href="source/drivers/cpufreq/cpufreq.c#L775">775</a>                         continue;
<a name="L776" href="source/drivers/cpufreq/cpufreq.c#L776">776</a>                 if (!<a href="ident?i=cpu_online">cpu_online</a>(j))
<a name="L777" href="source/drivers/cpufreq/cpufreq.c#L777">777</a>                         continue;
<a name="L778" href="source/drivers/cpufreq/cpufreq.c#L778">778</a> 
<a name="L779" href="source/drivers/cpufreq/cpufreq.c#L779">779</a>                 <a href="ident?i=pr_debug">pr_debug</a>(<i>"CPU %u already managed, adding link\n"</i>, j);
<a name="L780" href="source/drivers/cpufreq/cpufreq.c#L780">780</a>                 managed_policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L781" href="source/drivers/cpufreq/cpufreq.c#L781">781</a>                 <a href="ident?i=cpu_dev">cpu_dev</a> = <a href="ident?i=get_cpu_device">get_cpu_device</a>(j);
<a name="L782" href="source/drivers/cpufreq/cpufreq.c#L782">782</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=sysfs_create_link">sysfs_create_link</a>(&amp;<a href="ident?i=cpu_dev">cpu_dev</a>-&gt;<a href="ident?i=kobj">kobj</a>, &amp;policy-&gt;<a href="ident?i=kobj">kobj</a>,
<a name="L783" href="source/drivers/cpufreq/cpufreq.c#L783">783</a>                                         <i>"cpufreq"</i>);
<a name="L784" href="source/drivers/cpufreq/cpufreq.c#L784">784</a>                 if (<a href="ident?i=ret">ret</a>) {
<a name="L785" href="source/drivers/cpufreq/cpufreq.c#L785">785</a>                         <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(managed_policy);
<a name="L786" href="source/drivers/cpufreq/cpufreq.c#L786">786</a>                         return <a href="ident?i=ret">ret</a>;
<a name="L787" href="source/drivers/cpufreq/cpufreq.c#L787">787</a>                 }
<a name="L788" href="source/drivers/cpufreq/cpufreq.c#L788">788</a>         }
<a name="L789" href="source/drivers/cpufreq/cpufreq.c#L789">789</a>         return <a href="ident?i=ret">ret</a>;
<a name="L790" href="source/drivers/cpufreq/cpufreq.c#L790">790</a> }
<a name="L791" href="source/drivers/cpufreq/cpufreq.c#L791">791</a> 
<a name="L792" href="source/drivers/cpufreq/cpufreq.c#L792">792</a> static int <a href="ident?i=cpufreq_add_dev_interface">cpufreq_add_dev_interface</a>(unsigned int <a href="ident?i=cpu">cpu</a>,
<a name="L793" href="source/drivers/cpufreq/cpufreq.c#L793">793</a>                                      struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy,
<a name="L794" href="source/drivers/cpufreq/cpufreq.c#L794">794</a>                                      struct <a href="ident?i=device">device</a> *<a href="ident?i=dev">dev</a>)
<a name="L795" href="source/drivers/cpufreq/cpufreq.c#L795">795</a> {
<a name="L796" href="source/drivers/cpufreq/cpufreq.c#L796">796</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> new_policy;
<a name="L797" href="source/drivers/cpufreq/cpufreq.c#L797">797</a>         struct <a href="ident?i=freq_attr">freq_attr</a> **drv_attr;
<a name="L798" href="source/drivers/cpufreq/cpufreq.c#L798">798</a>         unsigned long <a href="ident?i=flags">flags</a>;
<a name="L799" href="source/drivers/cpufreq/cpufreq.c#L799">799</a>         int <a href="ident?i=ret">ret</a> = 0;
<a name="L800" href="source/drivers/cpufreq/cpufreq.c#L800">800</a>         unsigned int j;
<a name="L801" href="source/drivers/cpufreq/cpufreq.c#L801">801</a> 
<a name="L802" href="source/drivers/cpufreq/cpufreq.c#L802">802</a>         <b><i>/* prepare interface data */</i></b>
<a name="L803" href="source/drivers/cpufreq/cpufreq.c#L803">803</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=kobject_init_and_add">kobject_init_and_add</a>(&amp;policy-&gt;<a href="ident?i=kobj">kobj</a>, &amp;<a href="ident?i=ktype_cpufreq">ktype_cpufreq</a>,
<a name="L804" href="source/drivers/cpufreq/cpufreq.c#L804">804</a>                                    &amp;<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=kobj">kobj</a>, <i>"cpufreq"</i>);
<a name="L805" href="source/drivers/cpufreq/cpufreq.c#L805">805</a>         if (<a href="ident?i=ret">ret</a>)
<a name="L806" href="source/drivers/cpufreq/cpufreq.c#L806">806</a>                 return <a href="ident?i=ret">ret</a>;
<a name="L807" href="source/drivers/cpufreq/cpufreq.c#L807">807</a> 
<a name="L808" href="source/drivers/cpufreq/cpufreq.c#L808">808</a>         <b><i>/* set up files for this cpu device */</i></b>
<a name="L809" href="source/drivers/cpufreq/cpufreq.c#L809">809</a>         drv_attr = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=attr">attr</a>;
<a name="L810" href="source/drivers/cpufreq/cpufreq.c#L810">810</a>         while ((drv_attr) &amp;&amp; (*drv_attr)) {
<a name="L811" href="source/drivers/cpufreq/cpufreq.c#L811">811</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=sysfs_create_file">sysfs_create_file</a>(&amp;policy-&gt;<a href="ident?i=kobj">kobj</a>, &amp;((*drv_attr)-&gt;<a href="ident?i=attr">attr</a>));
<a name="L812" href="source/drivers/cpufreq/cpufreq.c#L812">812</a>                 if (<a href="ident?i=ret">ret</a>)
<a name="L813" href="source/drivers/cpufreq/cpufreq.c#L813">813</a>                         goto err_out_kobj_put;
<a name="L814" href="source/drivers/cpufreq/cpufreq.c#L814">814</a>                 drv_attr++;
<a name="L815" href="source/drivers/cpufreq/cpufreq.c#L815">815</a>         }
<a name="L816" href="source/drivers/cpufreq/cpufreq.c#L816">816</a>         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=get">get</a>) {
<a name="L817" href="source/drivers/cpufreq/cpufreq.c#L817">817</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=sysfs_create_file">sysfs_create_file</a>(&amp;policy-&gt;<a href="ident?i=kobj">kobj</a>, &amp;cpuinfo_cur_freq.<a href="ident?i=attr">attr</a>);
<a name="L818" href="source/drivers/cpufreq/cpufreq.c#L818">818</a>                 if (<a href="ident?i=ret">ret</a>)
<a name="L819" href="source/drivers/cpufreq/cpufreq.c#L819">819</a>                         goto err_out_kobj_put;
<a name="L820" href="source/drivers/cpufreq/cpufreq.c#L820">820</a>         }
<a name="L821" href="source/drivers/cpufreq/cpufreq.c#L821">821</a>         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=target">target</a>) {
<a name="L822" href="source/drivers/cpufreq/cpufreq.c#L822">822</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=sysfs_create_file">sysfs_create_file</a>(&amp;policy-&gt;<a href="ident?i=kobj">kobj</a>, &amp;scaling_cur_freq.<a href="ident?i=attr">attr</a>);
<a name="L823" href="source/drivers/cpufreq/cpufreq.c#L823">823</a>                 if (<a href="ident?i=ret">ret</a>)
<a name="L824" href="source/drivers/cpufreq/cpufreq.c#L824">824</a>                         goto err_out_kobj_put;
<a name="L825" href="source/drivers/cpufreq/cpufreq.c#L825">825</a>         }
<a name="L826" href="source/drivers/cpufreq/cpufreq.c#L826">826</a>         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;bios_limit) {
<a name="L827" href="source/drivers/cpufreq/cpufreq.c#L827">827</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=sysfs_create_file">sysfs_create_file</a>(&amp;policy-&gt;<a href="ident?i=kobj">kobj</a>, &amp;bios_limit.<a href="ident?i=attr">attr</a>);
<a name="L828" href="source/drivers/cpufreq/cpufreq.c#L828">828</a>                 if (<a href="ident?i=ret">ret</a>)
<a name="L829" href="source/drivers/cpufreq/cpufreq.c#L829">829</a>                         goto err_out_kobj_put;
<a name="L830" href="source/drivers/cpufreq/cpufreq.c#L830">830</a>         }
<a name="L831" href="source/drivers/cpufreq/cpufreq.c#L831">831</a> 
<a name="L832" href="source/drivers/cpufreq/cpufreq.c#L832">832</a>         <a href="ident?i=spin_lock_irqsave">spin_lock_irqsave</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L833" href="source/drivers/cpufreq/cpufreq.c#L833">833</a>         <a href="ident?i=for_each_cpu">for_each_cpu</a>(j, policy-&gt;cpus) {
<a name="L834" href="source/drivers/cpufreq/cpufreq.c#L834">834</a>                 if (!<a href="ident?i=cpu_online">cpu_online</a>(j))
<a name="L835" href="source/drivers/cpufreq/cpufreq.c#L835">835</a>                         continue;
<a name="L836" href="source/drivers/cpufreq/cpufreq.c#L836">836</a>                 <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_data, j) = policy;
<a name="L837" href="source/drivers/cpufreq/cpufreq.c#L837">837</a>                 <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_policy_cpu, j) = policy-&gt;<a href="ident?i=cpu">cpu</a>;
<a name="L838" href="source/drivers/cpufreq/cpufreq.c#L838">838</a>         }
<a name="L839" href="source/drivers/cpufreq/cpufreq.c#L839">839</a>         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L840" href="source/drivers/cpufreq/cpufreq.c#L840">840</a> 
<a name="L841" href="source/drivers/cpufreq/cpufreq.c#L841">841</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_add_dev_symlink">cpufreq_add_dev_symlink</a>(<a href="ident?i=cpu">cpu</a>, policy);
<a name="L842" href="source/drivers/cpufreq/cpufreq.c#L842">842</a>         if (<a href="ident?i=ret">ret</a>)
<a name="L843" href="source/drivers/cpufreq/cpufreq.c#L843">843</a>                 goto err_out_kobj_put;
<a name="L844" href="source/drivers/cpufreq/cpufreq.c#L844">844</a> 
<a name="L845" href="source/drivers/cpufreq/cpufreq.c#L845">845</a>         <a href="ident?i=memcpy">memcpy</a>(&amp;new_policy, policy, sizeof(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a>));
<a name="L846" href="source/drivers/cpufreq/cpufreq.c#L846">846</a>         <b><i>/* assure that the starting sequence is run in __cpufreq_set_policy */</i></b>
<a name="L847" href="source/drivers/cpufreq/cpufreq.c#L847">847</a>         policy-&gt;governor = <a href="ident?i=NULL">NULL</a>;
<a name="L848" href="source/drivers/cpufreq/cpufreq.c#L848">848</a> 
<a name="L849" href="source/drivers/cpufreq/cpufreq.c#L849">849</a>         <b><i>/* set default policy */</i></b>
<a name="L850" href="source/drivers/cpufreq/cpufreq.c#L850">850</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=__cpufreq_set_policy">__cpufreq_set_policy</a>(policy, &amp;new_policy);
<a name="L851" href="source/drivers/cpufreq/cpufreq.c#L851">851</a>         policy-&gt;user_policy.policy = policy-&gt;policy;
<a name="L852" href="source/drivers/cpufreq/cpufreq.c#L852">852</a>         policy-&gt;user_policy.governor = policy-&gt;governor;
<a name="L853" href="source/drivers/cpufreq/cpufreq.c#L853">853</a> 
<a name="L854" href="source/drivers/cpufreq/cpufreq.c#L854">854</a>         if (<a href="ident?i=ret">ret</a>) {
<a name="L855" href="source/drivers/cpufreq/cpufreq.c#L855">855</a>                 <a href="ident?i=pr_debug">pr_debug</a>(<i>"setting policy failed\n"</i>);
<a name="L856" href="source/drivers/cpufreq/cpufreq.c#L856">856</a>                 if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=exit">exit</a>)
<a name="L857" href="source/drivers/cpufreq/cpufreq.c#L857">857</a>                         <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=exit">exit</a>(policy);
<a name="L858" href="source/drivers/cpufreq/cpufreq.c#L858">858</a>         }
<a name="L859" href="source/drivers/cpufreq/cpufreq.c#L859">859</a>         return <a href="ident?i=ret">ret</a>;
<a name="L860" href="source/drivers/cpufreq/cpufreq.c#L860">860</a> 
<a name="L861" href="source/drivers/cpufreq/cpufreq.c#L861">861</a> err_out_kobj_put:
<a name="L862" href="source/drivers/cpufreq/cpufreq.c#L862">862</a>         <a href="ident?i=kobject_put">kobject_put</a>(&amp;policy-&gt;<a href="ident?i=kobj">kobj</a>);
<a name="L863" href="source/drivers/cpufreq/cpufreq.c#L863">863</a>         <a href="ident?i=wait_for_completion">wait_for_completion</a>(&amp;policy-&gt;kobj_unregister);
<a name="L864" href="source/drivers/cpufreq/cpufreq.c#L864">864</a>         return <a href="ident?i=ret">ret</a>;
<a name="L865" href="source/drivers/cpufreq/cpufreq.c#L865">865</a> }
<a name="L866" href="source/drivers/cpufreq/cpufreq.c#L866">866</a> 
<a name="L867" href="source/drivers/cpufreq/cpufreq.c#L867">867</a> 
<a name="L868" href="source/drivers/cpufreq/cpufreq.c#L868">868</a> <b><i>/**</i></b>
<a name="L869" href="source/drivers/cpufreq/cpufreq.c#L869">869</a> <b><i> * cpufreq_add_dev - add a CPU device</i></b>
<a name="L870" href="source/drivers/cpufreq/cpufreq.c#L870">870</a> <b><i> *</i></b>
<a name="L871" href="source/drivers/cpufreq/cpufreq.c#L871">871</a> <b><i> * Adds the cpufreq interface for a CPU device.</i></b>
<a name="L872" href="source/drivers/cpufreq/cpufreq.c#L872">872</a> <b><i> *</i></b>
<a name="L873" href="source/drivers/cpufreq/cpufreq.c#L873">873</a> <b><i> * The Oracle says: try running cpufreq registration/unregistration concurrently</i></b>
<a name="L874" href="source/drivers/cpufreq/cpufreq.c#L874">874</a> <b><i> * with with cpu hotplugging and all hell will break loose. Tried to clean this</i></b>
<a name="L875" href="source/drivers/cpufreq/cpufreq.c#L875">875</a> <b><i> * mess up, but more thorough testing is needed. - Mathieu</i></b>
<a name="L876" href="source/drivers/cpufreq/cpufreq.c#L876">876</a> <b><i> */</i></b>
<a name="L877" href="source/drivers/cpufreq/cpufreq.c#L877">877</a> static int <a href="ident?i=cpufreq_add_dev">cpufreq_add_dev</a>(struct <a href="ident?i=device">device</a> *<a href="ident?i=dev">dev</a>, struct <a href="ident?i=subsys_interface">subsys_interface</a> *sif)
<a name="L878" href="source/drivers/cpufreq/cpufreq.c#L878">878</a> {
<a name="L879" href="source/drivers/cpufreq/cpufreq.c#L879">879</a>         unsigned int <a href="ident?i=cpu">cpu</a> = <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=id">id</a>;
<a name="L880" href="source/drivers/cpufreq/cpufreq.c#L880">880</a>         int <a href="ident?i=ret">ret</a> = 0, <a href="ident?i=found">found</a> = 0;
<a name="L881" href="source/drivers/cpufreq/cpufreq.c#L881">881</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy;
<a name="L882" href="source/drivers/cpufreq/cpufreq.c#L882">882</a>         unsigned long <a href="ident?i=flags">flags</a>;
<a name="L883" href="source/drivers/cpufreq/cpufreq.c#L883">883</a>         unsigned int j;
<a name="L884" href="source/drivers/cpufreq/cpufreq.c#L884">884</a> #ifdef CONFIG_HOTPLUG_CPU
<a name="L885" href="source/drivers/cpufreq/cpufreq.c#L885">885</a>         int sibling;
<a name="L886" href="source/drivers/cpufreq/cpufreq.c#L886">886</a> #endif
<a name="L887" href="source/drivers/cpufreq/cpufreq.c#L887">887</a> 
<a name="L888" href="source/drivers/cpufreq/cpufreq.c#L888">888</a>         if (<a href="ident?i=cpu_is_offline">cpu_is_offline</a>(<a href="ident?i=cpu">cpu</a>))
<a name="L889" href="source/drivers/cpufreq/cpufreq.c#L889">889</a>                 return 0;
<a name="L890" href="source/drivers/cpufreq/cpufreq.c#L890">890</a> 
<a name="L891" href="source/drivers/cpufreq/cpufreq.c#L891">891</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"adding CPU %u\n"</i>, <a href="ident?i=cpu">cpu</a>);
<a name="L892" href="source/drivers/cpufreq/cpufreq.c#L892">892</a> 
<a name="L893" href="source/drivers/cpufreq/cpufreq.c#L893">893</a> #ifdef <a href="ident?i=CONFIG_SMP">CONFIG_SMP</a>
<a name="L894" href="source/drivers/cpufreq/cpufreq.c#L894">894</a>         <b><i>/* check whether a different CPU already registered this</i></b>
<a name="L895" href="source/drivers/cpufreq/cpufreq.c#L895">895</a> <b><i>         * CPU because it is in the same boat. */</i></b>
<a name="L896" href="source/drivers/cpufreq/cpufreq.c#L896">896</a>         policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L897" href="source/drivers/cpufreq/cpufreq.c#L897">897</a>         if (<a href="ident?i=unlikely">unlikely</a>(policy)) {
<a name="L898" href="source/drivers/cpufreq/cpufreq.c#L898">898</a>                 <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(policy);
<a name="L899" href="source/drivers/cpufreq/cpufreq.c#L899">899</a>                 return 0;
<a name="L900" href="source/drivers/cpufreq/cpufreq.c#L900">900</a>         }
<a name="L901" href="source/drivers/cpufreq/cpufreq.c#L901">901</a> #endif
<a name="L902" href="source/drivers/cpufreq/cpufreq.c#L902">902</a> 
<a name="L903" href="source/drivers/cpufreq/cpufreq.c#L903">903</a>         if (!<a href="ident?i=try_module_get">try_module_get</a>(<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;owner)) {
<a name="L904" href="source/drivers/cpufreq/cpufreq.c#L904">904</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L905" href="source/drivers/cpufreq/cpufreq.c#L905">905</a>                 goto module_out;
<a name="L906" href="source/drivers/cpufreq/cpufreq.c#L906">906</a>         }
<a name="L907" href="source/drivers/cpufreq/cpufreq.c#L907">907</a> 
<a name="L908" href="source/drivers/cpufreq/cpufreq.c#L908">908</a>         <a href="ident?i=ret">ret</a> = -<a href="ident?i=ENOMEM">ENOMEM</a>;
<a name="L909" href="source/drivers/cpufreq/cpufreq.c#L909">909</a>         policy = <a href="ident?i=kzalloc">kzalloc</a>(sizeof(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a>), <a href="ident?i=GFP_KERNEL">GFP_KERNEL</a>);
<a name="L910" href="source/drivers/cpufreq/cpufreq.c#L910">910</a>         if (!policy)
<a name="L911" href="source/drivers/cpufreq/cpufreq.c#L911">911</a>                 goto nomem_out;
<a name="L912" href="source/drivers/cpufreq/cpufreq.c#L912">912</a> 
<a name="L913" href="source/drivers/cpufreq/cpufreq.c#L913">913</a>         if (!<a href="ident?i=alloc_cpumask_var">alloc_cpumask_var</a>(&amp;policy-&gt;cpus, <a href="ident?i=GFP_KERNEL">GFP_KERNEL</a>))
<a name="L914" href="source/drivers/cpufreq/cpufreq.c#L914">914</a>                 goto err_free_policy;
<a name="L915" href="source/drivers/cpufreq/cpufreq.c#L915">915</a> 
<a name="L916" href="source/drivers/cpufreq/cpufreq.c#L916">916</a>         if (!<a href="ident?i=zalloc_cpumask_var">zalloc_cpumask_var</a>(&amp;policy-&gt;related_cpus, <a href="ident?i=GFP_KERNEL">GFP_KERNEL</a>))
<a name="L917" href="source/drivers/cpufreq/cpufreq.c#L917">917</a>                 goto err_free_cpumask;
<a name="L918" href="source/drivers/cpufreq/cpufreq.c#L918">918</a> 
<a name="L919" href="source/drivers/cpufreq/cpufreq.c#L919">919</a>         policy-&gt;<a href="ident?i=cpu">cpu</a> = <a href="ident?i=cpu">cpu</a>;
<a name="L920" href="source/drivers/cpufreq/cpufreq.c#L920">920</a>         <a href="ident?i=cpumask_copy">cpumask_copy</a>(policy-&gt;cpus, <a href="ident?i=cpumask_of">cpumask_of</a>(<a href="ident?i=cpu">cpu</a>));
<a name="L921" href="source/drivers/cpufreq/cpufreq.c#L921">921</a> 
<a name="L922" href="source/drivers/cpufreq/cpufreq.c#L922">922</a>         <b><i>/* Initially set CPU itself as the policy_cpu */</i></b>
<a name="L923" href="source/drivers/cpufreq/cpufreq.c#L923">923</a>         <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_policy_cpu, <a href="ident?i=cpu">cpu</a>) = <a href="ident?i=cpu">cpu</a>;
<a name="L924" href="source/drivers/cpufreq/cpufreq.c#L924">924</a>         <a href="ident?i=ret">ret</a> = (lock_policy_rwsem_write(<a href="ident?i=cpu">cpu</a>) &lt; 0);
<a name="L925" href="source/drivers/cpufreq/cpufreq.c#L925">925</a>         <a href="ident?i=WARN_ON">WARN_ON</a>(<a href="ident?i=ret">ret</a>);
<a name="L926" href="source/drivers/cpufreq/cpufreq.c#L926">926</a> 
<a name="L927" href="source/drivers/cpufreq/cpufreq.c#L927">927</a>         <a href="ident?i=init_completion">init_completion</a>(&amp;policy-&gt;kobj_unregister);
<a name="L928" href="source/drivers/cpufreq/cpufreq.c#L928">928</a>         <a href="ident?i=INIT_WORK">INIT_WORK</a>(&amp;policy-&gt;<a href="ident?i=update">update</a>, <a href="ident?i=handle_update">handle_update</a>);
<a name="L929" href="source/drivers/cpufreq/cpufreq.c#L929">929</a> 
<a name="L930" href="source/drivers/cpufreq/cpufreq.c#L930">930</a>         <b><i>/* Set governor before -&gt;init, so that driver could check it */</i></b>
<a name="L931" href="source/drivers/cpufreq/cpufreq.c#L931">931</a> #ifdef CONFIG_HOTPLUG_CPU
<a name="L932" href="source/drivers/cpufreq/cpufreq.c#L932">932</a>         <a href="ident?i=for_each_online_cpu">for_each_online_cpu</a>(sibling) {
<a name="L933" href="source/drivers/cpufreq/cpufreq.c#L933">933</a>                 struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *<a href="ident?i=cp">cp</a> = <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_data, sibling);
<a name="L934" href="source/drivers/cpufreq/cpufreq.c#L934">934</a>                 if (<a href="ident?i=cp">cp</a> &amp;&amp; <a href="ident?i=cp">cp</a>-&gt;governor &amp;&amp;
<a name="L935" href="source/drivers/cpufreq/cpufreq.c#L935">935</a>                     (<a href="ident?i=cpumask_test_cpu">cpumask_test_cpu</a>(<a href="ident?i=cpu">cpu</a>, <a href="ident?i=cp">cp</a>-&gt;related_cpus))) {
<a name="L936" href="source/drivers/cpufreq/cpufreq.c#L936">936</a>                         policy-&gt;governor = <a href="ident?i=cp">cp</a>-&gt;governor;
<a name="L937" href="source/drivers/cpufreq/cpufreq.c#L937">937</a>                         <a href="ident?i=found">found</a> = 1;
<a name="L938" href="source/drivers/cpufreq/cpufreq.c#L938">938</a>                         break;
<a name="L939" href="source/drivers/cpufreq/cpufreq.c#L939">939</a>                 }
<a name="L940" href="source/drivers/cpufreq/cpufreq.c#L940">940</a>         }
<a name="L941" href="source/drivers/cpufreq/cpufreq.c#L941">941</a> #endif
<a name="L942" href="source/drivers/cpufreq/cpufreq.c#L942">942</a>         if (!<a href="ident?i=found">found</a>)
<a name="L943" href="source/drivers/cpufreq/cpufreq.c#L943">943</a>                 policy-&gt;governor = <a href="ident?i=CPUFREQ_DEFAULT_GOVERNOR">CPUFREQ_DEFAULT_GOVERNOR</a>;
<a name="L944" href="source/drivers/cpufreq/cpufreq.c#L944">944</a>         <b><i>/* call driver. From then on the cpufreq must be able</i></b>
<a name="L945" href="source/drivers/cpufreq/cpufreq.c#L945">945</a> <b><i>         * to accept all calls to -&gt;verify and -&gt;setpolicy for this CPU</i></b>
<a name="L946" href="source/drivers/cpufreq/cpufreq.c#L946">946</a> <b><i>         */</i></b>
<a name="L947" href="source/drivers/cpufreq/cpufreq.c#L947">947</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=init">init</a>(policy);
<a name="L948" href="source/drivers/cpufreq/cpufreq.c#L948">948</a>         if (<a href="ident?i=ret">ret</a>) {
<a name="L949" href="source/drivers/cpufreq/cpufreq.c#L949">949</a>                 <a href="ident?i=pr_debug">pr_debug</a>(<i>"initialization failed\n"</i>);
<a name="L950" href="source/drivers/cpufreq/cpufreq.c#L950">950</a>                 goto err_unlock_policy;
<a name="L951" href="source/drivers/cpufreq/cpufreq.c#L951">951</a>         }
<a name="L952" href="source/drivers/cpufreq/cpufreq.c#L952">952</a>         policy-&gt;user_policy.<a href="ident?i=min">min</a> = policy-&gt;<a href="ident?i=min">min</a>;
<a name="L953" href="source/drivers/cpufreq/cpufreq.c#L953">953</a>         policy-&gt;user_policy.<a href="ident?i=max">max</a> = policy-&gt;<a href="ident?i=max">max</a>;
<a name="L954" href="source/drivers/cpufreq/cpufreq.c#L954">954</a> 
<a name="L955" href="source/drivers/cpufreq/cpufreq.c#L955">955</a>         <a href="ident?i=blocking_notifier_call_chain">blocking_notifier_call_chain</a>(&amp;cpufreq_policy_notifier_list,
<a name="L956" href="source/drivers/cpufreq/cpufreq.c#L956">956</a>                                      <a href="ident?i=CPUFREQ_START">CPUFREQ_START</a>, policy);
<a name="L957" href="source/drivers/cpufreq/cpufreq.c#L957">957</a> 
<a name="L958" href="source/drivers/cpufreq/cpufreq.c#L958">958</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_add_dev_policy">cpufreq_add_dev_policy</a>(<a href="ident?i=cpu">cpu</a>, policy, <a href="ident?i=dev">dev</a>);
<a name="L959" href="source/drivers/cpufreq/cpufreq.c#L959">959</a>         if (<a href="ident?i=ret">ret</a>) {
<a name="L960" href="source/drivers/cpufreq/cpufreq.c#L960">960</a>                 if (<a href="ident?i=ret">ret</a> &gt; 0)
<a name="L961" href="source/drivers/cpufreq/cpufreq.c#L961">961</a>                         <b><i>/* This is a managed cpu, symlink created,</i></b>
<a name="L962" href="source/drivers/cpufreq/cpufreq.c#L962">962</a> <b><i>                           exit with 0 */</i></b>
<a name="L963" href="source/drivers/cpufreq/cpufreq.c#L963">963</a>                         <a href="ident?i=ret">ret</a> = 0;
<a name="L964" href="source/drivers/cpufreq/cpufreq.c#L964">964</a>                 goto err_unlock_policy;
<a name="L965" href="source/drivers/cpufreq/cpufreq.c#L965">965</a>         }
<a name="L966" href="source/drivers/cpufreq/cpufreq.c#L966">966</a> 
<a name="L967" href="source/drivers/cpufreq/cpufreq.c#L967">967</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_add_dev_interface">cpufreq_add_dev_interface</a>(<a href="ident?i=cpu">cpu</a>, policy, <a href="ident?i=dev">dev</a>);
<a name="L968" href="source/drivers/cpufreq/cpufreq.c#L968">968</a>         if (<a href="ident?i=ret">ret</a>)
<a name="L969" href="source/drivers/cpufreq/cpufreq.c#L969">969</a>                 goto err_out_unregister;
<a name="L970" href="source/drivers/cpufreq/cpufreq.c#L970">970</a> 
<a name="L971" href="source/drivers/cpufreq/cpufreq.c#L971">971</a>         <a href="ident?i=unlock_policy_rwsem_write">unlock_policy_rwsem_write</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L972" href="source/drivers/cpufreq/cpufreq.c#L972">972</a> 
<a name="L973" href="source/drivers/cpufreq/cpufreq.c#L973">973</a>         <a href="ident?i=kobject_uevent">kobject_uevent</a>(&amp;policy-&gt;<a href="ident?i=kobj">kobj</a>, KOBJ_ADD);
<a name="L974" href="source/drivers/cpufreq/cpufreq.c#L974">974</a>         <a href="ident?i=module_put">module_put</a>(<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;owner);
<a name="L975" href="source/drivers/cpufreq/cpufreq.c#L975">975</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"initialization complete\n"</i>);
<a name="L976" href="source/drivers/cpufreq/cpufreq.c#L976">976</a> 
<a name="L977" href="source/drivers/cpufreq/cpufreq.c#L977">977</a>         return 0;
<a name="L978" href="source/drivers/cpufreq/cpufreq.c#L978">978</a> 
<a name="L979" href="source/drivers/cpufreq/cpufreq.c#L979">979</a> 
<a name="L980" href="source/drivers/cpufreq/cpufreq.c#L980">980</a> err_out_unregister:
<a name="L981" href="source/drivers/cpufreq/cpufreq.c#L981">981</a>         <a href="ident?i=spin_lock_irqsave">spin_lock_irqsave</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L982" href="source/drivers/cpufreq/cpufreq.c#L982">982</a>         <a href="ident?i=for_each_cpu">for_each_cpu</a>(j, policy-&gt;cpus)
<a name="L983" href="source/drivers/cpufreq/cpufreq.c#L983">983</a>                 <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_data, j) = <a href="ident?i=NULL">NULL</a>;
<a name="L984" href="source/drivers/cpufreq/cpufreq.c#L984">984</a>         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L985" href="source/drivers/cpufreq/cpufreq.c#L985">985</a> 
<a name="L986" href="source/drivers/cpufreq/cpufreq.c#L986">986</a>         <a href="ident?i=kobject_put">kobject_put</a>(&amp;policy-&gt;<a href="ident?i=kobj">kobj</a>);
<a name="L987" href="source/drivers/cpufreq/cpufreq.c#L987">987</a>         <a href="ident?i=wait_for_completion">wait_for_completion</a>(&amp;policy-&gt;kobj_unregister);
<a name="L988" href="source/drivers/cpufreq/cpufreq.c#L988">988</a> 
<a name="L989" href="source/drivers/cpufreq/cpufreq.c#L989">989</a> err_unlock_policy:
<a name="L990" href="source/drivers/cpufreq/cpufreq.c#L990">990</a>         <a href="ident?i=unlock_policy_rwsem_write">unlock_policy_rwsem_write</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L991" href="source/drivers/cpufreq/cpufreq.c#L991">991</a>         <a href="ident?i=free_cpumask_var">free_cpumask_var</a>(policy-&gt;related_cpus);
<a name="L992" href="source/drivers/cpufreq/cpufreq.c#L992">992</a> err_free_cpumask:
<a name="L993" href="source/drivers/cpufreq/cpufreq.c#L993">993</a>         <a href="ident?i=free_cpumask_var">free_cpumask_var</a>(policy-&gt;cpus);
<a name="L994" href="source/drivers/cpufreq/cpufreq.c#L994">994</a> err_free_policy:
<a name="L995" href="source/drivers/cpufreq/cpufreq.c#L995">995</a>         <a href="ident?i=kfree">kfree</a>(policy);
<a name="L996" href="source/drivers/cpufreq/cpufreq.c#L996">996</a> nomem_out:
<a name="L997" href="source/drivers/cpufreq/cpufreq.c#L997">997</a>         <a href="ident?i=module_put">module_put</a>(<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;owner);
<a name="L998" href="source/drivers/cpufreq/cpufreq.c#L998">998</a> module_out:
<a name="L999" href="source/drivers/cpufreq/cpufreq.c#L999">999</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1000" href="source/drivers/cpufreq/cpufreq.c#L1000">1000</a> }
<a name="L1001" href="source/drivers/cpufreq/cpufreq.c#L1001">1001</a> 
<a name="L1002" href="source/drivers/cpufreq/cpufreq.c#L1002">1002</a> 
<a name="L1003" href="source/drivers/cpufreq/cpufreq.c#L1003">1003</a> <b><i>/**</i></b>
<a name="L1004" href="source/drivers/cpufreq/cpufreq.c#L1004">1004</a> <b><i> * __cpufreq_remove_dev - remove a CPU device</i></b>
<a name="L1005" href="source/drivers/cpufreq/cpufreq.c#L1005">1005</a> <b><i> *</i></b>
<a name="L1006" href="source/drivers/cpufreq/cpufreq.c#L1006">1006</a> <b><i> * Removes the cpufreq interface for a CPU device.</i></b>
<a name="L1007" href="source/drivers/cpufreq/cpufreq.c#L1007">1007</a> <b><i> * Caller should already have policy_rwsem in write mode for this CPU.</i></b>
<a name="L1008" href="source/drivers/cpufreq/cpufreq.c#L1008">1008</a> <b><i> * This routine frees the rwsem before returning.</i></b>
<a name="L1009" href="source/drivers/cpufreq/cpufreq.c#L1009">1009</a> <b><i> */</i></b>
<a name="L1010" href="source/drivers/cpufreq/cpufreq.c#L1010">1010</a> static int <a href="ident?i=__cpufreq_remove_dev">__cpufreq_remove_dev</a>(struct <a href="ident?i=device">device</a> *<a href="ident?i=dev">dev</a>, struct <a href="ident?i=subsys_interface">subsys_interface</a> *sif)
<a name="L1011" href="source/drivers/cpufreq/cpufreq.c#L1011">1011</a> {
<a name="L1012" href="source/drivers/cpufreq/cpufreq.c#L1012">1012</a>         unsigned int <a href="ident?i=cpu">cpu</a> = <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=id">id</a>;
<a name="L1013" href="source/drivers/cpufreq/cpufreq.c#L1013">1013</a>         unsigned long <a href="ident?i=flags">flags</a>;
<a name="L1014" href="source/drivers/cpufreq/cpufreq.c#L1014">1014</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *<a href="ident?i=data">data</a>;
<a name="L1015" href="source/drivers/cpufreq/cpufreq.c#L1015">1015</a>         struct <a href="ident?i=kobject">kobject</a> *<a href="ident?i=kobj">kobj</a>;
<a name="L1016" href="source/drivers/cpufreq/cpufreq.c#L1016">1016</a>         struct <a href="ident?i=completion">completion</a> *<a href="ident?i=cmp">cmp</a>;
<a name="L1017" href="source/drivers/cpufreq/cpufreq.c#L1017">1017</a> #ifdef <a href="ident?i=CONFIG_SMP">CONFIG_SMP</a>
<a name="L1018" href="source/drivers/cpufreq/cpufreq.c#L1018">1018</a>         struct <a href="ident?i=device">device</a> *<a href="ident?i=cpu_dev">cpu_dev</a>;
<a name="L1019" href="source/drivers/cpufreq/cpufreq.c#L1019">1019</a>         unsigned int j;
<a name="L1020" href="source/drivers/cpufreq/cpufreq.c#L1020">1020</a> #endif
<a name="L1021" href="source/drivers/cpufreq/cpufreq.c#L1021">1021</a> 
<a name="L1022" href="source/drivers/cpufreq/cpufreq.c#L1022">1022</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"unregistering CPU %u\n"</i>, <a href="ident?i=cpu">cpu</a>);
<a name="L1023" href="source/drivers/cpufreq/cpufreq.c#L1023">1023</a> 
<a name="L1024" href="source/drivers/cpufreq/cpufreq.c#L1024">1024</a>         <a href="ident?i=spin_lock_irqsave">spin_lock_irqsave</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L1025" href="source/drivers/cpufreq/cpufreq.c#L1025">1025</a>         <a href="ident?i=data">data</a> = <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_data, <a href="ident?i=cpu">cpu</a>);
<a name="L1026" href="source/drivers/cpufreq/cpufreq.c#L1026">1026</a> 
<a name="L1027" href="source/drivers/cpufreq/cpufreq.c#L1027">1027</a>         if (!<a href="ident?i=data">data</a>) {
<a name="L1028" href="source/drivers/cpufreq/cpufreq.c#L1028">1028</a>                 <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L1029" href="source/drivers/cpufreq/cpufreq.c#L1029">1029</a>                 <a href="ident?i=unlock_policy_rwsem_write">unlock_policy_rwsem_write</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1030" href="source/drivers/cpufreq/cpufreq.c#L1030">1030</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1031" href="source/drivers/cpufreq/cpufreq.c#L1031">1031</a>         }
<a name="L1032" href="source/drivers/cpufreq/cpufreq.c#L1032">1032</a>         <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_data, <a href="ident?i=cpu">cpu</a>) = <a href="ident?i=NULL">NULL</a>;
<a name="L1033" href="source/drivers/cpufreq/cpufreq.c#L1033">1033</a> 
<a name="L1034" href="source/drivers/cpufreq/cpufreq.c#L1034">1034</a> 
<a name="L1035" href="source/drivers/cpufreq/cpufreq.c#L1035">1035</a> #ifdef <a href="ident?i=CONFIG_SMP">CONFIG_SMP</a>
<a name="L1036" href="source/drivers/cpufreq/cpufreq.c#L1036">1036</a>         <b><i>/* if this isn't the CPU which is the parent of the kobj, we</i></b>
<a name="L1037" href="source/drivers/cpufreq/cpufreq.c#L1037">1037</a> <b><i>         * only need to unlink, put and exit</i></b>
<a name="L1038" href="source/drivers/cpufreq/cpufreq.c#L1038">1038</a> <b><i>         */</i></b>
<a name="L1039" href="source/drivers/cpufreq/cpufreq.c#L1039">1039</a>         if (<a href="ident?i=unlikely">unlikely</a>(<a href="ident?i=cpu">cpu</a> != <a href="ident?i=data">data</a>-&gt;<a href="ident?i=cpu">cpu</a>)) {
<a name="L1040" href="source/drivers/cpufreq/cpufreq.c#L1040">1040</a>                 <a href="ident?i=pr_debug">pr_debug</a>(<i>"removing link\n"</i>);
<a name="L1041" href="source/drivers/cpufreq/cpufreq.c#L1041">1041</a>                 <a href="ident?i=cpumask_clear_cpu">cpumask_clear_cpu</a>(<a href="ident?i=cpu">cpu</a>, <a href="ident?i=data">data</a>-&gt;cpus);
<a name="L1042" href="source/drivers/cpufreq/cpufreq.c#L1042">1042</a>                 <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L1043" href="source/drivers/cpufreq/cpufreq.c#L1043">1043</a>                 <a href="ident?i=kobj">kobj</a> = &amp;<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=kobj">kobj</a>;
<a name="L1044" href="source/drivers/cpufreq/cpufreq.c#L1044">1044</a>                 <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(<a href="ident?i=data">data</a>);
<a name="L1045" href="source/drivers/cpufreq/cpufreq.c#L1045">1045</a>                 <a href="ident?i=unlock_policy_rwsem_write">unlock_policy_rwsem_write</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1046" href="source/drivers/cpufreq/cpufreq.c#L1046">1046</a>                 <a href="ident?i=sysfs_remove_link">sysfs_remove_link</a>(<a href="ident?i=kobj">kobj</a>, <i>"cpufreq"</i>);
<a name="L1047" href="source/drivers/cpufreq/cpufreq.c#L1047">1047</a>                 return 0;
<a name="L1048" href="source/drivers/cpufreq/cpufreq.c#L1048">1048</a>         }
<a name="L1049" href="source/drivers/cpufreq/cpufreq.c#L1049">1049</a> #endif
<a name="L1050" href="source/drivers/cpufreq/cpufreq.c#L1050">1050</a> 
<a name="L1051" href="source/drivers/cpufreq/cpufreq.c#L1051">1051</a> #ifdef <a href="ident?i=CONFIG_SMP">CONFIG_SMP</a>
<a name="L1052" href="source/drivers/cpufreq/cpufreq.c#L1052">1052</a> 
<a name="L1053" href="source/drivers/cpufreq/cpufreq.c#L1053">1053</a> #ifdef CONFIG_HOTPLUG_CPU
<a name="L1054" href="source/drivers/cpufreq/cpufreq.c#L1054">1054</a>         <a href="ident?i=strncpy">strncpy</a>(<a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_governor, <a href="ident?i=cpu">cpu</a>), <a href="ident?i=data">data</a>-&gt;governor-&gt;<a href="ident?i=name">name</a>,
<a name="L1055" href="source/drivers/cpufreq/cpufreq.c#L1055">1055</a>                         <a href="ident?i=CPUFREQ_NAME_LEN">CPUFREQ_NAME_LEN</a>);
<a name="L1056" href="source/drivers/cpufreq/cpufreq.c#L1056">1056</a> #endif
<a name="L1057" href="source/drivers/cpufreq/cpufreq.c#L1057">1057</a> 
<a name="L1058" href="source/drivers/cpufreq/cpufreq.c#L1058">1058</a>         <b><i>/* if we have other CPUs still registered, we need to unlink them,</i></b>
<a name="L1059" href="source/drivers/cpufreq/cpufreq.c#L1059">1059</a> <b><i>         * or else wait_for_completion below will lock up. Clean the</i></b>
<a name="L1060" href="source/drivers/cpufreq/cpufreq.c#L1060">1060</a> <b><i>         * per_cpu(cpufreq_cpu_data) while holding the lock, and remove</i></b>
<a name="L1061" href="source/drivers/cpufreq/cpufreq.c#L1061">1061</a> <b><i>         * the sysfs links afterwards.</i></b>
<a name="L1062" href="source/drivers/cpufreq/cpufreq.c#L1062">1062</a> <b><i>         */</i></b>
<a name="L1063" href="source/drivers/cpufreq/cpufreq.c#L1063">1063</a>         if (<a href="ident?i=unlikely">unlikely</a>(<a href="ident?i=cpumask_weight">cpumask_weight</a>(<a href="ident?i=data">data</a>-&gt;cpus) &gt; 1)) {
<a name="L1064" href="source/drivers/cpufreq/cpufreq.c#L1064">1064</a>                 <a href="ident?i=for_each_cpu">for_each_cpu</a>(j, <a href="ident?i=data">data</a>-&gt;cpus) {
<a name="L1065" href="source/drivers/cpufreq/cpufreq.c#L1065">1065</a>                         if (j == <a href="ident?i=cpu">cpu</a>)
<a name="L1066" href="source/drivers/cpufreq/cpufreq.c#L1066">1066</a>                                 continue;
<a name="L1067" href="source/drivers/cpufreq/cpufreq.c#L1067">1067</a>                         <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_data, j) = <a href="ident?i=NULL">NULL</a>;
<a name="L1068" href="source/drivers/cpufreq/cpufreq.c#L1068">1068</a>                 }
<a name="L1069" href="source/drivers/cpufreq/cpufreq.c#L1069">1069</a>         }
<a name="L1070" href="source/drivers/cpufreq/cpufreq.c#L1070">1070</a> 
<a name="L1071" href="source/drivers/cpufreq/cpufreq.c#L1071">1071</a>         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L1072" href="source/drivers/cpufreq/cpufreq.c#L1072">1072</a> 
<a name="L1073" href="source/drivers/cpufreq/cpufreq.c#L1073">1073</a>         if (<a href="ident?i=unlikely">unlikely</a>(<a href="ident?i=cpumask_weight">cpumask_weight</a>(<a href="ident?i=data">data</a>-&gt;cpus) &gt; 1)) {
<a name="L1074" href="source/drivers/cpufreq/cpufreq.c#L1074">1074</a>                 <a href="ident?i=for_each_cpu">for_each_cpu</a>(j, <a href="ident?i=data">data</a>-&gt;cpus) {
<a name="L1075" href="source/drivers/cpufreq/cpufreq.c#L1075">1075</a>                         if (j == <a href="ident?i=cpu">cpu</a>)
<a name="L1076" href="source/drivers/cpufreq/cpufreq.c#L1076">1076</a>                                 continue;
<a name="L1077" href="source/drivers/cpufreq/cpufreq.c#L1077">1077</a>                         <a href="ident?i=pr_debug">pr_debug</a>(<i>"removing link for cpu %u\n"</i>, j);
<a name="L1078" href="source/drivers/cpufreq/cpufreq.c#L1078">1078</a> #ifdef CONFIG_HOTPLUG_CPU
<a name="L1079" href="source/drivers/cpufreq/cpufreq.c#L1079">1079</a>                         <a href="ident?i=strncpy">strncpy</a>(<a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_governor, j),
<a name="L1080" href="source/drivers/cpufreq/cpufreq.c#L1080">1080</a>                                 <a href="ident?i=data">data</a>-&gt;governor-&gt;<a href="ident?i=name">name</a>, <a href="ident?i=CPUFREQ_NAME_LEN">CPUFREQ_NAME_LEN</a>);
<a name="L1081" href="source/drivers/cpufreq/cpufreq.c#L1081">1081</a> #endif
<a name="L1082" href="source/drivers/cpufreq/cpufreq.c#L1082">1082</a>                         <a href="ident?i=cpu_dev">cpu_dev</a> = <a href="ident?i=get_cpu_device">get_cpu_device</a>(j);
<a name="L1083" href="source/drivers/cpufreq/cpufreq.c#L1083">1083</a>                         <a href="ident?i=kobj">kobj</a> = &amp;<a href="ident?i=cpu_dev">cpu_dev</a>-&gt;<a href="ident?i=kobj">kobj</a>;
<a name="L1084" href="source/drivers/cpufreq/cpufreq.c#L1084">1084</a>                         <a href="ident?i=unlock_policy_rwsem_write">unlock_policy_rwsem_write</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1085" href="source/drivers/cpufreq/cpufreq.c#L1085">1085</a>                         <a href="ident?i=sysfs_remove_link">sysfs_remove_link</a>(<a href="ident?i=kobj">kobj</a>, <i>"cpufreq"</i>);
<a name="L1086" href="source/drivers/cpufreq/cpufreq.c#L1086">1086</a>                         lock_policy_rwsem_write(<a href="ident?i=cpu">cpu</a>);
<a name="L1087" href="source/drivers/cpufreq/cpufreq.c#L1087">1087</a>                         <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(<a href="ident?i=data">data</a>);
<a name="L1088" href="source/drivers/cpufreq/cpufreq.c#L1088">1088</a>                 }
<a name="L1089" href="source/drivers/cpufreq/cpufreq.c#L1089">1089</a>         }
<a name="L1090" href="source/drivers/cpufreq/cpufreq.c#L1090">1090</a> #else
<a name="L1091" href="source/drivers/cpufreq/cpufreq.c#L1091">1091</a>         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L1092" href="source/drivers/cpufreq/cpufreq.c#L1092">1092</a> #endif
<a name="L1093" href="source/drivers/cpufreq/cpufreq.c#L1093">1093</a> 
<a name="L1094" href="source/drivers/cpufreq/cpufreq.c#L1094">1094</a>         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=target">target</a>)
<a name="L1095" href="source/drivers/cpufreq/cpufreq.c#L1095">1095</a>                 <a href="ident?i=__cpufreq_governor">__cpufreq_governor</a>(<a href="ident?i=data">data</a>, <a href="ident?i=CPUFREQ_GOV_STOP">CPUFREQ_GOV_STOP</a>);
<a name="L1096" href="source/drivers/cpufreq/cpufreq.c#L1096">1096</a> 
<a name="L1097" href="source/drivers/cpufreq/cpufreq.c#L1097">1097</a>         <a href="ident?i=kobj">kobj</a> = &amp;<a href="ident?i=data">data</a>-&gt;<a href="ident?i=kobj">kobj</a>;
<a name="L1098" href="source/drivers/cpufreq/cpufreq.c#L1098">1098</a>         <a href="ident?i=cmp">cmp</a> = &amp;<a href="ident?i=data">data</a>-&gt;kobj_unregister;
<a name="L1099" href="source/drivers/cpufreq/cpufreq.c#L1099">1099</a>         <a href="ident?i=unlock_policy_rwsem_write">unlock_policy_rwsem_write</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1100" href="source/drivers/cpufreq/cpufreq.c#L1100">1100</a>         <a href="ident?i=kobject_put">kobject_put</a>(<a href="ident?i=kobj">kobj</a>);
<a name="L1101" href="source/drivers/cpufreq/cpufreq.c#L1101">1101</a> 
<a name="L1102" href="source/drivers/cpufreq/cpufreq.c#L1102">1102</a>         <b><i>/* we need to make sure that the underlying kobj is actually</i></b>
<a name="L1103" href="source/drivers/cpufreq/cpufreq.c#L1103">1103</a> <b><i>         * not referenced anymore by anybody before we proceed with</i></b>
<a name="L1104" href="source/drivers/cpufreq/cpufreq.c#L1104">1104</a> <b><i>         * unloading.</i></b>
<a name="L1105" href="source/drivers/cpufreq/cpufreq.c#L1105">1105</a> <b><i>         */</i></b>
<a name="L1106" href="source/drivers/cpufreq/cpufreq.c#L1106">1106</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"waiting for dropping of refcount\n"</i>);
<a name="L1107" href="source/drivers/cpufreq/cpufreq.c#L1107">1107</a>         <a href="ident?i=wait_for_completion">wait_for_completion</a>(<a href="ident?i=cmp">cmp</a>);
<a name="L1108" href="source/drivers/cpufreq/cpufreq.c#L1108">1108</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"wait complete\n"</i>);
<a name="L1109" href="source/drivers/cpufreq/cpufreq.c#L1109">1109</a> 
<a name="L1110" href="source/drivers/cpufreq/cpufreq.c#L1110">1110</a>         lock_policy_rwsem_write(<a href="ident?i=cpu">cpu</a>);
<a name="L1111" href="source/drivers/cpufreq/cpufreq.c#L1111">1111</a>         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=exit">exit</a>)
<a name="L1112" href="source/drivers/cpufreq/cpufreq.c#L1112">1112</a>                 <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=exit">exit</a>(<a href="ident?i=data">data</a>);
<a name="L1113" href="source/drivers/cpufreq/cpufreq.c#L1113">1113</a>         <a href="ident?i=unlock_policy_rwsem_write">unlock_policy_rwsem_write</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1114" href="source/drivers/cpufreq/cpufreq.c#L1114">1114</a> 
<a name="L1115" href="source/drivers/cpufreq/cpufreq.c#L1115">1115</a> #ifdef CONFIG_HOTPLUG_CPU
<a name="L1116" href="source/drivers/cpufreq/cpufreq.c#L1116">1116</a>         <b><i>/* when the CPU which is the parent of the kobj is hotplugged</i></b>
<a name="L1117" href="source/drivers/cpufreq/cpufreq.c#L1117">1117</a> <b><i>         * offline, check for siblings, and create cpufreq sysfs interface</i></b>
<a name="L1118" href="source/drivers/cpufreq/cpufreq.c#L1118">1118</a> <b><i>         * and symlinks</i></b>
<a name="L1119" href="source/drivers/cpufreq/cpufreq.c#L1119">1119</a> <b><i>         */</i></b>
<a name="L1120" href="source/drivers/cpufreq/cpufreq.c#L1120">1120</a>         if (<a href="ident?i=unlikely">unlikely</a>(<a href="ident?i=cpumask_weight">cpumask_weight</a>(<a href="ident?i=data">data</a>-&gt;cpus) &gt; 1)) {
<a name="L1121" href="source/drivers/cpufreq/cpufreq.c#L1121">1121</a>                 <b><i>/* first sibling now owns the new sysfs dir */</i></b>
<a name="L1122" href="source/drivers/cpufreq/cpufreq.c#L1122">1122</a>                 <a href="ident?i=cpumask_clear_cpu">cpumask_clear_cpu</a>(<a href="ident?i=cpu">cpu</a>, <a href="ident?i=data">data</a>-&gt;cpus);
<a name="L1123" href="source/drivers/cpufreq/cpufreq.c#L1123">1123</a>                 <a href="ident?i=cpufreq_add_dev">cpufreq_add_dev</a>(<a href="ident?i=get_cpu_device">get_cpu_device</a>(<a href="ident?i=cpumask_first">cpumask_first</a>(<a href="ident?i=data">data</a>-&gt;cpus)), <a href="ident?i=NULL">NULL</a>);
<a name="L1124" href="source/drivers/cpufreq/cpufreq.c#L1124">1124</a> 
<a name="L1125" href="source/drivers/cpufreq/cpufreq.c#L1125">1125</a>                 <b><i>/* finally remove our own symlink */</i></b>
<a name="L1126" href="source/drivers/cpufreq/cpufreq.c#L1126">1126</a>                 lock_policy_rwsem_write(<a href="ident?i=cpu">cpu</a>);
<a name="L1127" href="source/drivers/cpufreq/cpufreq.c#L1127">1127</a>                 <a href="ident?i=__cpufreq_remove_dev">__cpufreq_remove_dev</a>(<a href="ident?i=dev">dev</a>, sif);
<a name="L1128" href="source/drivers/cpufreq/cpufreq.c#L1128">1128</a>         }
<a name="L1129" href="source/drivers/cpufreq/cpufreq.c#L1129">1129</a> #endif
<a name="L1130" href="source/drivers/cpufreq/cpufreq.c#L1130">1130</a> 
<a name="L1131" href="source/drivers/cpufreq/cpufreq.c#L1131">1131</a>         <a href="ident?i=free_cpumask_var">free_cpumask_var</a>(<a href="ident?i=data">data</a>-&gt;related_cpus);
<a name="L1132" href="source/drivers/cpufreq/cpufreq.c#L1132">1132</a>         <a href="ident?i=free_cpumask_var">free_cpumask_var</a>(<a href="ident?i=data">data</a>-&gt;cpus);
<a name="L1133" href="source/drivers/cpufreq/cpufreq.c#L1133">1133</a>         <a href="ident?i=kfree">kfree</a>(<a href="ident?i=data">data</a>);
<a name="L1134" href="source/drivers/cpufreq/cpufreq.c#L1134">1134</a> 
<a name="L1135" href="source/drivers/cpufreq/cpufreq.c#L1135">1135</a>         return 0;
<a name="L1136" href="source/drivers/cpufreq/cpufreq.c#L1136">1136</a> }
<a name="L1137" href="source/drivers/cpufreq/cpufreq.c#L1137">1137</a> 
<a name="L1138" href="source/drivers/cpufreq/cpufreq.c#L1138">1138</a> 
<a name="L1139" href="source/drivers/cpufreq/cpufreq.c#L1139">1139</a> static int <a href="ident?i=cpufreq_remove_dev">cpufreq_remove_dev</a>(struct <a href="ident?i=device">device</a> *<a href="ident?i=dev">dev</a>, struct <a href="ident?i=subsys_interface">subsys_interface</a> *sif)
<a name="L1140" href="source/drivers/cpufreq/cpufreq.c#L1140">1140</a> {
<a name="L1141" href="source/drivers/cpufreq/cpufreq.c#L1141">1141</a>         unsigned int <a href="ident?i=cpu">cpu</a> = <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=id">id</a>;
<a name="L1142" href="source/drivers/cpufreq/cpufreq.c#L1142">1142</a>         int retval;
<a name="L1143" href="source/drivers/cpufreq/cpufreq.c#L1143">1143</a> 
<a name="L1144" href="source/drivers/cpufreq/cpufreq.c#L1144">1144</a>         if (<a href="ident?i=cpu_is_offline">cpu_is_offline</a>(<a href="ident?i=cpu">cpu</a>))
<a name="L1145" href="source/drivers/cpufreq/cpufreq.c#L1145">1145</a>                 return 0;
<a name="L1146" href="source/drivers/cpufreq/cpufreq.c#L1146">1146</a> 
<a name="L1147" href="source/drivers/cpufreq/cpufreq.c#L1147">1147</a>         if (<a href="ident?i=unlikely">unlikely</a>(lock_policy_rwsem_write(<a href="ident?i=cpu">cpu</a>)))
<a name="L1148" href="source/drivers/cpufreq/cpufreq.c#L1148">1148</a>                 <a href="ident?i=BUG">BUG</a>();
<a name="L1149" href="source/drivers/cpufreq/cpufreq.c#L1149">1149</a> 
<a name="L1150" href="source/drivers/cpufreq/cpufreq.c#L1150">1150</a>         retval = <a href="ident?i=__cpufreq_remove_dev">__cpufreq_remove_dev</a>(<a href="ident?i=dev">dev</a>, sif);
<a name="L1151" href="source/drivers/cpufreq/cpufreq.c#L1151">1151</a>         return retval;
<a name="L1152" href="source/drivers/cpufreq/cpufreq.c#L1152">1152</a> }
<a name="L1153" href="source/drivers/cpufreq/cpufreq.c#L1153">1153</a> 
<a name="L1154" href="source/drivers/cpufreq/cpufreq.c#L1154">1154</a> 
<a name="L1155" href="source/drivers/cpufreq/cpufreq.c#L1155">1155</a> static void <a href="ident?i=handle_update">handle_update</a>(struct <a href="ident?i=work_struct">work_struct</a> *<a href="ident?i=work">work</a>)
<a name="L1156" href="source/drivers/cpufreq/cpufreq.c#L1156">1156</a> {
<a name="L1157" href="source/drivers/cpufreq/cpufreq.c#L1157">1157</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy =
<a name="L1158" href="source/drivers/cpufreq/cpufreq.c#L1158">1158</a>                 <a href="ident?i=container_of">container_of</a>(<a href="ident?i=work">work</a>, struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a>, <a href="ident?i=update">update</a>);
<a name="L1159" href="source/drivers/cpufreq/cpufreq.c#L1159">1159</a>         unsigned int <a href="ident?i=cpu">cpu</a> = policy-&gt;<a href="ident?i=cpu">cpu</a>;
<a name="L1160" href="source/drivers/cpufreq/cpufreq.c#L1160">1160</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"handle_update for cpu %u called\n"</i>, <a href="ident?i=cpu">cpu</a>);
<a name="L1161" href="source/drivers/cpufreq/cpufreq.c#L1161">1161</a>         <a href="ident?i=cpufreq_update_policy">cpufreq_update_policy</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1162" href="source/drivers/cpufreq/cpufreq.c#L1162">1162</a> }
<a name="L1163" href="source/drivers/cpufreq/cpufreq.c#L1163">1163</a> 
<a name="L1164" href="source/drivers/cpufreq/cpufreq.c#L1164">1164</a> <b><i>/**</i></b>
<a name="L1165" href="source/drivers/cpufreq/cpufreq.c#L1165">1165</a> <b><i> *      cpufreq_out_of_sync - If actual and saved CPU frequency differs, we're in deep trouble.</i></b>
<a name="L1166" href="source/drivers/cpufreq/cpufreq.c#L1166">1166</a> <b><i> *      @cpu: cpu number</i></b>
<a name="L1167" href="source/drivers/cpufreq/cpufreq.c#L1167">1167</a> <b><i> *      @old_freq: CPU frequency the kernel thinks the CPU runs at</i></b>
<a name="L1168" href="source/drivers/cpufreq/cpufreq.c#L1168">1168</a> <b><i> *      @new_freq: CPU frequency the CPU actually runs at</i></b>
<a name="L1169" href="source/drivers/cpufreq/cpufreq.c#L1169">1169</a> <b><i> *</i></b>
<a name="L1170" href="source/drivers/cpufreq/cpufreq.c#L1170">1170</a> <b><i> *      We adjust to current frequency first, and need to clean up later.</i></b>
<a name="L1171" href="source/drivers/cpufreq/cpufreq.c#L1171">1171</a> <b><i> *      So either call to cpufreq_update_policy() or schedule handle_update()).</i></b>
<a name="L1172" href="source/drivers/cpufreq/cpufreq.c#L1172">1172</a> <b><i> */</i></b>
<a name="L1173" href="source/drivers/cpufreq/cpufreq.c#L1173">1173</a> static void <a href="ident?i=cpufreq_out_of_sync">cpufreq_out_of_sync</a>(unsigned int <a href="ident?i=cpu">cpu</a>, unsigned int old_freq,
<a name="L1174" href="source/drivers/cpufreq/cpufreq.c#L1174">1174</a>                                 unsigned int new_freq)
<a name="L1175" href="source/drivers/cpufreq/cpufreq.c#L1175">1175</a> {
<a name="L1176" href="source/drivers/cpufreq/cpufreq.c#L1176">1176</a>         struct <a href="ident?i=cpufreq_freqs">cpufreq_freqs</a> <a href="ident?i=freqs">freqs</a>;
<a name="L1177" href="source/drivers/cpufreq/cpufreq.c#L1177">1177</a> 
<a name="L1178" href="source/drivers/cpufreq/cpufreq.c#L1178">1178</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"Warning: CPU frequency out of sync: cpufreq and timing "</i>
<a name="L1179" href="source/drivers/cpufreq/cpufreq.c#L1179">1179</a>                <i>"core thinks of %u, is %u kHz.\n"</i>, old_freq, new_freq);
<a name="L1180" href="source/drivers/cpufreq/cpufreq.c#L1180">1180</a> 
<a name="L1181" href="source/drivers/cpufreq/cpufreq.c#L1181">1181</a>         <a href="ident?i=freqs">freqs</a>.<a href="ident?i=cpu">cpu</a> = <a href="ident?i=cpu">cpu</a>;
<a name="L1182" href="source/drivers/cpufreq/cpufreq.c#L1182">1182</a>         <a href="ident?i=freqs">freqs</a>.old = old_freq;
<a name="L1183" href="source/drivers/cpufreq/cpufreq.c#L1183">1183</a>         <a href="ident?i=freqs">freqs</a>.new = new_freq;
<a name="L1184" href="source/drivers/cpufreq/cpufreq.c#L1184">1184</a>         <a href="ident?i=cpufreq_notify_transition">cpufreq_notify_transition</a>(&amp;<a href="ident?i=freqs">freqs</a>, <a href="ident?i=CPUFREQ_PRECHANGE">CPUFREQ_PRECHANGE</a>);
<a name="L1185" href="source/drivers/cpufreq/cpufreq.c#L1185">1185</a>         <a href="ident?i=cpufreq_notify_transition">cpufreq_notify_transition</a>(&amp;<a href="ident?i=freqs">freqs</a>, <a href="ident?i=CPUFREQ_POSTCHANGE">CPUFREQ_POSTCHANGE</a>);
<a name="L1186" href="source/drivers/cpufreq/cpufreq.c#L1186">1186</a> }
<a name="L1187" href="source/drivers/cpufreq/cpufreq.c#L1187">1187</a> 
<a name="L1188" href="source/drivers/cpufreq/cpufreq.c#L1188">1188</a> 
<a name="L1189" href="source/drivers/cpufreq/cpufreq.c#L1189">1189</a> <b><i>/**</i></b>
<a name="L1190" href="source/drivers/cpufreq/cpufreq.c#L1190">1190</a> <b><i> * cpufreq_quick_get - get the CPU frequency (in kHz) from policy-&gt;cur</i></b>
<a name="L1191" href="source/drivers/cpufreq/cpufreq.c#L1191">1191</a> <b><i> * @cpu: CPU number</i></b>
<a name="L1192" href="source/drivers/cpufreq/cpufreq.c#L1192">1192</a> <b><i> *</i></b>
<a name="L1193" href="source/drivers/cpufreq/cpufreq.c#L1193">1193</a> <b><i> * This is the last known freq, without actually getting it from the driver.</i></b>
<a name="L1194" href="source/drivers/cpufreq/cpufreq.c#L1194">1194</a> <b><i> * Return value will be same as what is shown in scaling_cur_freq in sysfs.</i></b>
<a name="L1195" href="source/drivers/cpufreq/cpufreq.c#L1195">1195</a> <b><i> */</i></b>
<a name="L1196" href="source/drivers/cpufreq/cpufreq.c#L1196">1196</a> unsigned int <a href="ident?i=cpufreq_quick_get">cpufreq_quick_get</a>(unsigned int <a href="ident?i=cpu">cpu</a>)
<a name="L1197" href="source/drivers/cpufreq/cpufreq.c#L1197">1197</a> {
<a name="L1198" href="source/drivers/cpufreq/cpufreq.c#L1198">1198</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1199" href="source/drivers/cpufreq/cpufreq.c#L1199">1199</a>         unsigned int ret_freq = 0;
<a name="L1200" href="source/drivers/cpufreq/cpufreq.c#L1200">1200</a> 
<a name="L1201" href="source/drivers/cpufreq/cpufreq.c#L1201">1201</a>         if (policy) {
<a name="L1202" href="source/drivers/cpufreq/cpufreq.c#L1202">1202</a>                 ret_freq = policy-&gt;cur;
<a name="L1203" href="source/drivers/cpufreq/cpufreq.c#L1203">1203</a>                 <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(policy);
<a name="L1204" href="source/drivers/cpufreq/cpufreq.c#L1204">1204</a>         }
<a name="L1205" href="source/drivers/cpufreq/cpufreq.c#L1205">1205</a> 
<a name="L1206" href="source/drivers/cpufreq/cpufreq.c#L1206">1206</a>         return ret_freq;
<a name="L1207" href="source/drivers/cpufreq/cpufreq.c#L1207">1207</a> }
<a name="L1208" href="source/drivers/cpufreq/cpufreq.c#L1208">1208</a> <a href="ident?i=EXPORT_SYMBOL">EXPORT_SYMBOL</a>(<a href="ident?i=cpufreq_quick_get">cpufreq_quick_get</a>);
<a name="L1209" href="source/drivers/cpufreq/cpufreq.c#L1209">1209</a> 
<a name="L1210" href="source/drivers/cpufreq/cpufreq.c#L1210">1210</a> <b><i>/**</i></b>
<a name="L1211" href="source/drivers/cpufreq/cpufreq.c#L1211">1211</a> <b><i> * cpufreq_quick_get_max - get the max reported CPU frequency for this CPU</i></b>
<a name="L1212" href="source/drivers/cpufreq/cpufreq.c#L1212">1212</a> <b><i> * @cpu: CPU number</i></b>
<a name="L1213" href="source/drivers/cpufreq/cpufreq.c#L1213">1213</a> <b><i> *</i></b>
<a name="L1214" href="source/drivers/cpufreq/cpufreq.c#L1214">1214</a> <b><i> * Just return the max possible frequency for a given CPU.</i></b>
<a name="L1215" href="source/drivers/cpufreq/cpufreq.c#L1215">1215</a> <b><i> */</i></b>
<a name="L1216" href="source/drivers/cpufreq/cpufreq.c#L1216">1216</a> unsigned int <a href="ident?i=cpufreq_quick_get_max">cpufreq_quick_get_max</a>(unsigned int <a href="ident?i=cpu">cpu</a>)
<a name="L1217" href="source/drivers/cpufreq/cpufreq.c#L1217">1217</a> {
<a name="L1218" href="source/drivers/cpufreq/cpufreq.c#L1218">1218</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1219" href="source/drivers/cpufreq/cpufreq.c#L1219">1219</a>         unsigned int ret_freq = 0;
<a name="L1220" href="source/drivers/cpufreq/cpufreq.c#L1220">1220</a> 
<a name="L1221" href="source/drivers/cpufreq/cpufreq.c#L1221">1221</a>         if (policy) {
<a name="L1222" href="source/drivers/cpufreq/cpufreq.c#L1222">1222</a>                 ret_freq = policy-&gt;<a href="ident?i=max">max</a>;
<a name="L1223" href="source/drivers/cpufreq/cpufreq.c#L1223">1223</a>                 <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(policy);
<a name="L1224" href="source/drivers/cpufreq/cpufreq.c#L1224">1224</a>         }
<a name="L1225" href="source/drivers/cpufreq/cpufreq.c#L1225">1225</a> 
<a name="L1226" href="source/drivers/cpufreq/cpufreq.c#L1226">1226</a>         return ret_freq;
<a name="L1227" href="source/drivers/cpufreq/cpufreq.c#L1227">1227</a> }
<a name="L1228" href="source/drivers/cpufreq/cpufreq.c#L1228">1228</a> <a href="ident?i=EXPORT_SYMBOL">EXPORT_SYMBOL</a>(<a href="ident?i=cpufreq_quick_get_max">cpufreq_quick_get_max</a>);
<a name="L1229" href="source/drivers/cpufreq/cpufreq.c#L1229">1229</a> 
<a name="L1230" href="source/drivers/cpufreq/cpufreq.c#L1230">1230</a> 
<a name="L1231" href="source/drivers/cpufreq/cpufreq.c#L1231">1231</a> static unsigned int <a href="ident?i=__cpufreq_get">__cpufreq_get</a>(unsigned int <a href="ident?i=cpu">cpu</a>)
<a name="L1232" href="source/drivers/cpufreq/cpufreq.c#L1232">1232</a> {
<a name="L1233" href="source/drivers/cpufreq/cpufreq.c#L1233">1233</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy = <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_data, <a href="ident?i=cpu">cpu</a>);
<a name="L1234" href="source/drivers/cpufreq/cpufreq.c#L1234">1234</a>         unsigned int ret_freq = 0;
<a name="L1235" href="source/drivers/cpufreq/cpufreq.c#L1235">1235</a> 
<a name="L1236" href="source/drivers/cpufreq/cpufreq.c#L1236">1236</a>         if (!<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=get">get</a>)
<a name="L1237" href="source/drivers/cpufreq/cpufreq.c#L1237">1237</a>                 return ret_freq;
<a name="L1238" href="source/drivers/cpufreq/cpufreq.c#L1238">1238</a> 
<a name="L1239" href="source/drivers/cpufreq/cpufreq.c#L1239">1239</a>         ret_freq = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=get">get</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1240" href="source/drivers/cpufreq/cpufreq.c#L1240">1240</a> 
<a name="L1241" href="source/drivers/cpufreq/cpufreq.c#L1241">1241</a>         if (ret_freq &amp;&amp; policy-&gt;cur &amp;&amp;
<a name="L1242" href="source/drivers/cpufreq/cpufreq.c#L1242">1242</a>                 !(<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=flags">flags</a> &amp; <a href="ident?i=CPUFREQ_CONST_LOOPS">CPUFREQ_CONST_LOOPS</a>)) {
<a name="L1243" href="source/drivers/cpufreq/cpufreq.c#L1243">1243</a>                 <b><i>/* verify no discrepancy between actual and</i></b>
<a name="L1244" href="source/drivers/cpufreq/cpufreq.c#L1244">1244</a> <b><i>                                        saved value exists */</i></b>
<a name="L1245" href="source/drivers/cpufreq/cpufreq.c#L1245">1245</a>                 if (<a href="ident?i=unlikely">unlikely</a>(ret_freq != policy-&gt;cur)) {
<a name="L1246" href="source/drivers/cpufreq/cpufreq.c#L1246">1246</a>                         <a href="ident?i=cpufreq_out_of_sync">cpufreq_out_of_sync</a>(<a href="ident?i=cpu">cpu</a>, policy-&gt;cur, ret_freq);
<a name="L1247" href="source/drivers/cpufreq/cpufreq.c#L1247">1247</a>                         <a href="ident?i=schedule_work">schedule_work</a>(&amp;policy-&gt;<a href="ident?i=update">update</a>);
<a name="L1248" href="source/drivers/cpufreq/cpufreq.c#L1248">1248</a>                 }
<a name="L1249" href="source/drivers/cpufreq/cpufreq.c#L1249">1249</a>         }
<a name="L1250" href="source/drivers/cpufreq/cpufreq.c#L1250">1250</a> 
<a name="L1251" href="source/drivers/cpufreq/cpufreq.c#L1251">1251</a>         return ret_freq;
<a name="L1252" href="source/drivers/cpufreq/cpufreq.c#L1252">1252</a> }
<a name="L1253" href="source/drivers/cpufreq/cpufreq.c#L1253">1253</a> 
<a name="L1254" href="source/drivers/cpufreq/cpufreq.c#L1254">1254</a> <b><i>/**</i></b>
<a name="L1255" href="source/drivers/cpufreq/cpufreq.c#L1255">1255</a> <b><i> * cpufreq_get - get the current CPU frequency (in kHz)</i></b>
<a name="L1256" href="source/drivers/cpufreq/cpufreq.c#L1256">1256</a> <b><i> * @cpu: CPU number</i></b>
<a name="L1257" href="source/drivers/cpufreq/cpufreq.c#L1257">1257</a> <b><i> *</i></b>
<a name="L1258" href="source/drivers/cpufreq/cpufreq.c#L1258">1258</a> <b><i> * Get the CPU current (static) CPU frequency</i></b>
<a name="L1259" href="source/drivers/cpufreq/cpufreq.c#L1259">1259</a> <b><i> */</i></b>
<a name="L1260" href="source/drivers/cpufreq/cpufreq.c#L1260">1260</a> unsigned int <a href="ident?i=cpufreq_get">cpufreq_get</a>(unsigned int <a href="ident?i=cpu">cpu</a>)
<a name="L1261" href="source/drivers/cpufreq/cpufreq.c#L1261">1261</a> {
<a name="L1262" href="source/drivers/cpufreq/cpufreq.c#L1262">1262</a>         unsigned int ret_freq = 0;
<a name="L1263" href="source/drivers/cpufreq/cpufreq.c#L1263">1263</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1264" href="source/drivers/cpufreq/cpufreq.c#L1264">1264</a> 
<a name="L1265" href="source/drivers/cpufreq/cpufreq.c#L1265">1265</a>         if (!policy)
<a name="L1266" href="source/drivers/cpufreq/cpufreq.c#L1266">1266</a>                 goto <a href="ident?i=out">out</a>;
<a name="L1267" href="source/drivers/cpufreq/cpufreq.c#L1267">1267</a> 
<a name="L1268" href="source/drivers/cpufreq/cpufreq.c#L1268">1268</a>         if (<a href="ident?i=unlikely">unlikely</a>(lock_policy_rwsem_read(<a href="ident?i=cpu">cpu</a>)))
<a name="L1269" href="source/drivers/cpufreq/cpufreq.c#L1269">1269</a>                 goto out_policy;
<a name="L1270" href="source/drivers/cpufreq/cpufreq.c#L1270">1270</a> 
<a name="L1271" href="source/drivers/cpufreq/cpufreq.c#L1271">1271</a>         ret_freq = <a href="ident?i=__cpufreq_get">__cpufreq_get</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1272" href="source/drivers/cpufreq/cpufreq.c#L1272">1272</a> 
<a name="L1273" href="source/drivers/cpufreq/cpufreq.c#L1273">1273</a>         <a href="ident?i=unlock_policy_rwsem_read">unlock_policy_rwsem_read</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1274" href="source/drivers/cpufreq/cpufreq.c#L1274">1274</a> 
<a name="L1275" href="source/drivers/cpufreq/cpufreq.c#L1275">1275</a> out_policy:
<a name="L1276" href="source/drivers/cpufreq/cpufreq.c#L1276">1276</a>         <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(policy);
<a name="L1277" href="source/drivers/cpufreq/cpufreq.c#L1277">1277</a> <a href="ident?i=out">out</a>:
<a name="L1278" href="source/drivers/cpufreq/cpufreq.c#L1278">1278</a>         return ret_freq;
<a name="L1279" href="source/drivers/cpufreq/cpufreq.c#L1279">1279</a> }
<a name="L1280" href="source/drivers/cpufreq/cpufreq.c#L1280">1280</a> <a href="ident?i=EXPORT_SYMBOL">EXPORT_SYMBOL</a>(<a href="ident?i=cpufreq_get">cpufreq_get</a>);
<a name="L1281" href="source/drivers/cpufreq/cpufreq.c#L1281">1281</a> 
<a name="L1282" href="source/drivers/cpufreq/cpufreq.c#L1282">1282</a> static struct <a href="ident?i=subsys_interface">subsys_interface</a> <a href="ident?i=cpufreq_interface">cpufreq_interface</a> = {
<a name="L1283" href="source/drivers/cpufreq/cpufreq.c#L1283">1283</a>         .<a href="ident?i=name">name</a>           = <i>"cpufreq"</i>,
<a name="L1284" href="source/drivers/cpufreq/cpufreq.c#L1284">1284</a>         .<a href="ident?i=subsys">subsys</a>         = &amp;<a href="ident?i=cpu_subsys">cpu_subsys</a>,
<a name="L1285" href="source/drivers/cpufreq/cpufreq.c#L1285">1285</a>         .<a href="ident?i=add_dev">add_dev</a>        = <a href="ident?i=cpufreq_add_dev">cpufreq_add_dev</a>,
<a name="L1286" href="source/drivers/cpufreq/cpufreq.c#L1286">1286</a>         .<a href="ident?i=remove_dev">remove_dev</a>     = <a href="ident?i=cpufreq_remove_dev">cpufreq_remove_dev</a>,
<a name="L1287" href="source/drivers/cpufreq/cpufreq.c#L1287">1287</a> };
<a name="L1288" href="source/drivers/cpufreq/cpufreq.c#L1288">1288</a> 
<a name="L1289" href="source/drivers/cpufreq/cpufreq.c#L1289">1289</a> 
<a name="L1290" href="source/drivers/cpufreq/cpufreq.c#L1290">1290</a> <b><i>/**</i></b>
<a name="L1291" href="source/drivers/cpufreq/cpufreq.c#L1291">1291</a> <b><i> * cpufreq_bp_suspend - Prepare the boot CPU for system suspend.</i></b>
<a name="L1292" href="source/drivers/cpufreq/cpufreq.c#L1292">1292</a> <b><i> *</i></b>
<a name="L1293" href="source/drivers/cpufreq/cpufreq.c#L1293">1293</a> <b><i> * This function is only executed for the boot processor.  The other CPUs</i></b>
<a name="L1294" href="source/drivers/cpufreq/cpufreq.c#L1294">1294</a> <b><i> * have been put offline by means of CPU hotplug.</i></b>
<a name="L1295" href="source/drivers/cpufreq/cpufreq.c#L1295">1295</a> <b><i> */</i></b>
<a name="L1296" href="source/drivers/cpufreq/cpufreq.c#L1296">1296</a> static int <a href="ident?i=cpufreq_bp_suspend">cpufreq_bp_suspend</a>(void)
<a name="L1297" href="source/drivers/cpufreq/cpufreq.c#L1297">1297</a> {
<a name="L1298" href="source/drivers/cpufreq/cpufreq.c#L1298">1298</a>         int <a href="ident?i=ret">ret</a> = 0;
<a name="L1299" href="source/drivers/cpufreq/cpufreq.c#L1299">1299</a> 
<a name="L1300" href="source/drivers/cpufreq/cpufreq.c#L1300">1300</a>         int <a href="ident?i=cpu">cpu</a> = <a href="ident?i=smp_processor_id">smp_processor_id</a>();
<a name="L1301" href="source/drivers/cpufreq/cpufreq.c#L1301">1301</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *cpu_policy;
<a name="L1302" href="source/drivers/cpufreq/cpufreq.c#L1302">1302</a> 
<a name="L1303" href="source/drivers/cpufreq/cpufreq.c#L1303">1303</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"suspending cpu %u\n"</i>, <a href="ident?i=cpu">cpu</a>);
<a name="L1304" href="source/drivers/cpufreq/cpufreq.c#L1304">1304</a> 
<a name="L1305" href="source/drivers/cpufreq/cpufreq.c#L1305">1305</a>         <b><i>/* If there's no policy for the boot CPU, we have nothing to do. */</i></b>
<a name="L1306" href="source/drivers/cpufreq/cpufreq.c#L1306">1306</a>         cpu_policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1307" href="source/drivers/cpufreq/cpufreq.c#L1307">1307</a>         if (!cpu_policy)
<a name="L1308" href="source/drivers/cpufreq/cpufreq.c#L1308">1308</a>                 return 0;
<a name="L1309" href="source/drivers/cpufreq/cpufreq.c#L1309">1309</a> 
<a name="L1310" href="source/drivers/cpufreq/cpufreq.c#L1310">1310</a>         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=suspend">suspend</a>) {
<a name="L1311" href="source/drivers/cpufreq/cpufreq.c#L1311">1311</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=suspend">suspend</a>(cpu_policy);
<a name="L1312" href="source/drivers/cpufreq/cpufreq.c#L1312">1312</a>                 if (<a href="ident?i=ret">ret</a>)
<a name="L1313" href="source/drivers/cpufreq/cpufreq.c#L1313">1313</a>                         <a href="ident?i=printk">printk</a>(<a href="ident?i=KERN_ERR">KERN_ERR</a> <i>"cpufreq: suspend failed in -&gt;suspend "</i>
<a name="L1314" href="source/drivers/cpufreq/cpufreq.c#L1314">1314</a>                                         <i>"step on CPU %u\n"</i>, cpu_policy-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L1315" href="source/drivers/cpufreq/cpufreq.c#L1315">1315</a>         }
<a name="L1316" href="source/drivers/cpufreq/cpufreq.c#L1316">1316</a> 
<a name="L1317" href="source/drivers/cpufreq/cpufreq.c#L1317">1317</a>         <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(cpu_policy);
<a name="L1318" href="source/drivers/cpufreq/cpufreq.c#L1318">1318</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1319" href="source/drivers/cpufreq/cpufreq.c#L1319">1319</a> }
<a name="L1320" href="source/drivers/cpufreq/cpufreq.c#L1320">1320</a> 
<a name="L1321" href="source/drivers/cpufreq/cpufreq.c#L1321">1321</a> <b><i>/**</i></b>
<a name="L1322" href="source/drivers/cpufreq/cpufreq.c#L1322">1322</a> <b><i> * cpufreq_bp_resume - Restore proper frequency handling of the boot CPU.</i></b>
<a name="L1323" href="source/drivers/cpufreq/cpufreq.c#L1323">1323</a> <b><i> *</i></b>
<a name="L1324" href="source/drivers/cpufreq/cpufreq.c#L1324">1324</a> <b><i> *      1.) resume CPUfreq hardware support (cpufreq_driver-&gt;resume())</i></b>
<a name="L1325" href="source/drivers/cpufreq/cpufreq.c#L1325">1325</a> <b><i> *      2.) schedule call cpufreq_update_policy() ASAP as interrupts are</i></b>
<a name="L1326" href="source/drivers/cpufreq/cpufreq.c#L1326">1326</a> <b><i> *          restored. It will verify that the current freq is in sync with</i></b>
<a name="L1327" href="source/drivers/cpufreq/cpufreq.c#L1327">1327</a> <b><i> *          what we believe it to be. This is a bit later than when it</i></b>
<a name="L1328" href="source/drivers/cpufreq/cpufreq.c#L1328">1328</a> <b><i> *          should be, but nonethteless it's better than calling</i></b>
<a name="L1329" href="source/drivers/cpufreq/cpufreq.c#L1329">1329</a> <b><i> *          cpufreq_driver-&gt;get() here which might re-enable interrupts...</i></b>
<a name="L1330" href="source/drivers/cpufreq/cpufreq.c#L1330">1330</a> <b><i> *</i></b>
<a name="L1331" href="source/drivers/cpufreq/cpufreq.c#L1331">1331</a> <b><i> * This function is only executed for the boot CPU.  The other CPUs have not</i></b>
<a name="L1332" href="source/drivers/cpufreq/cpufreq.c#L1332">1332</a> <b><i> * been turned on yet.</i></b>
<a name="L1333" href="source/drivers/cpufreq/cpufreq.c#L1333">1333</a> <b><i> */</i></b>
<a name="L1334" href="source/drivers/cpufreq/cpufreq.c#L1334">1334</a> static void <a href="ident?i=cpufreq_bp_resume">cpufreq_bp_resume</a>(void)
<a name="L1335" href="source/drivers/cpufreq/cpufreq.c#L1335">1335</a> {
<a name="L1336" href="source/drivers/cpufreq/cpufreq.c#L1336">1336</a>         int <a href="ident?i=ret">ret</a> = 0;
<a name="L1337" href="source/drivers/cpufreq/cpufreq.c#L1337">1337</a> 
<a name="L1338" href="source/drivers/cpufreq/cpufreq.c#L1338">1338</a>         int <a href="ident?i=cpu">cpu</a> = <a href="ident?i=smp_processor_id">smp_processor_id</a>();
<a name="L1339" href="source/drivers/cpufreq/cpufreq.c#L1339">1339</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *cpu_policy;
<a name="L1340" href="source/drivers/cpufreq/cpufreq.c#L1340">1340</a> 
<a name="L1341" href="source/drivers/cpufreq/cpufreq.c#L1341">1341</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"resuming cpu %u\n"</i>, <a href="ident?i=cpu">cpu</a>);
<a name="L1342" href="source/drivers/cpufreq/cpufreq.c#L1342">1342</a> 
<a name="L1343" href="source/drivers/cpufreq/cpufreq.c#L1343">1343</a>         <b><i>/* If there's no policy for the boot CPU, we have nothing to do. */</i></b>
<a name="L1344" href="source/drivers/cpufreq/cpufreq.c#L1344">1344</a>         cpu_policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1345" href="source/drivers/cpufreq/cpufreq.c#L1345">1345</a>         if (!cpu_policy)
<a name="L1346" href="source/drivers/cpufreq/cpufreq.c#L1346">1346</a>                 return;
<a name="L1347" href="source/drivers/cpufreq/cpufreq.c#L1347">1347</a> 
<a name="L1348" href="source/drivers/cpufreq/cpufreq.c#L1348">1348</a>         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=resume">resume</a>) {
<a name="L1349" href="source/drivers/cpufreq/cpufreq.c#L1349">1349</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=resume">resume</a>(cpu_policy);
<a name="L1350" href="source/drivers/cpufreq/cpufreq.c#L1350">1350</a>                 if (<a href="ident?i=ret">ret</a>) {
<a name="L1351" href="source/drivers/cpufreq/cpufreq.c#L1351">1351</a>                         <a href="ident?i=printk">printk</a>(<a href="ident?i=KERN_ERR">KERN_ERR</a> <i>"cpufreq: resume failed in -&gt;resume "</i>
<a name="L1352" href="source/drivers/cpufreq/cpufreq.c#L1352">1352</a>                                         <i>"step on CPU %u\n"</i>, cpu_policy-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L1353" href="source/drivers/cpufreq/cpufreq.c#L1353">1353</a>                         goto fail;
<a name="L1354" href="source/drivers/cpufreq/cpufreq.c#L1354">1354</a>                 }
<a name="L1355" href="source/drivers/cpufreq/cpufreq.c#L1355">1355</a>         }
<a name="L1356" href="source/drivers/cpufreq/cpufreq.c#L1356">1356</a> 
<a name="L1357" href="source/drivers/cpufreq/cpufreq.c#L1357">1357</a>         <a href="ident?i=schedule_work">schedule_work</a>(&amp;cpu_policy-&gt;<a href="ident?i=update">update</a>);
<a name="L1358" href="source/drivers/cpufreq/cpufreq.c#L1358">1358</a> 
<a name="L1359" href="source/drivers/cpufreq/cpufreq.c#L1359">1359</a> fail:
<a name="L1360" href="source/drivers/cpufreq/cpufreq.c#L1360">1360</a>         <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(cpu_policy);
<a name="L1361" href="source/drivers/cpufreq/cpufreq.c#L1361">1361</a> }
<a name="L1362" href="source/drivers/cpufreq/cpufreq.c#L1362">1362</a> 
<a name="L1363" href="source/drivers/cpufreq/cpufreq.c#L1363">1363</a> static struct <a href="ident?i=syscore_ops">syscore_ops</a> <a href="ident?i=cpufreq_syscore_ops">cpufreq_syscore_ops</a> = {
<a name="L1364" href="source/drivers/cpufreq/cpufreq.c#L1364">1364</a>         .<a href="ident?i=suspend">suspend</a>        = <a href="ident?i=cpufreq_bp_suspend">cpufreq_bp_suspend</a>,
<a name="L1365" href="source/drivers/cpufreq/cpufreq.c#L1365">1365</a>         .<a href="ident?i=resume">resume</a>         = <a href="ident?i=cpufreq_bp_resume">cpufreq_bp_resume</a>,
<a name="L1366" href="source/drivers/cpufreq/cpufreq.c#L1366">1366</a> };
<a name="L1367" href="source/drivers/cpufreq/cpufreq.c#L1367">1367</a> 
<a name="L1368" href="source/drivers/cpufreq/cpufreq.c#L1368">1368</a> 
<a name="L1369" href="source/drivers/cpufreq/cpufreq.c#L1369">1369</a> <b><i>/*********************************************************************</i></b>
<a name="L1370" href="source/drivers/cpufreq/cpufreq.c#L1370">1370</a> <b><i> *                     NOTIFIER LISTS INTERFACE                      *</i></b>
<a name="L1371" href="source/drivers/cpufreq/cpufreq.c#L1371">1371</a> <b><i> *********************************************************************/</i></b>
<a name="L1372" href="source/drivers/cpufreq/cpufreq.c#L1372">1372</a> 
<a name="L1373" href="source/drivers/cpufreq/cpufreq.c#L1373">1373</a> <b><i>/**</i></b>
<a name="L1374" href="source/drivers/cpufreq/cpufreq.c#L1374">1374</a> <b><i> *      cpufreq_register_notifier - register a driver with cpufreq</i></b>
<a name="L1375" href="source/drivers/cpufreq/cpufreq.c#L1375">1375</a> <b><i> *      @nb: notifier function to register</i></b>
<a name="L1376" href="source/drivers/cpufreq/cpufreq.c#L1376">1376</a> <b><i> *      @list: CPUFREQ_TRANSITION_NOTIFIER or CPUFREQ_POLICY_NOTIFIER</i></b>
<a name="L1377" href="source/drivers/cpufreq/cpufreq.c#L1377">1377</a> <b><i> *</i></b>
<a name="L1378" href="source/drivers/cpufreq/cpufreq.c#L1378">1378</a> <b><i> *      Add a driver to one of two lists: either a list of drivers that</i></b>
<a name="L1379" href="source/drivers/cpufreq/cpufreq.c#L1379">1379</a> <b><i> *      are notified about clock rate changes (once before and once after</i></b>
<a name="L1380" href="source/drivers/cpufreq/cpufreq.c#L1380">1380</a> <b><i> *      the transition), or a list of drivers that are notified about</i></b>
<a name="L1381" href="source/drivers/cpufreq/cpufreq.c#L1381">1381</a> <b><i> *      changes in cpufreq policy.</i></b>
<a name="L1382" href="source/drivers/cpufreq/cpufreq.c#L1382">1382</a> <b><i> *</i></b>
<a name="L1383" href="source/drivers/cpufreq/cpufreq.c#L1383">1383</a> <b><i> *      This function may sleep, and has the same return conditions as</i></b>
<a name="L1384" href="source/drivers/cpufreq/cpufreq.c#L1384">1384</a> <b><i> *      blocking_notifier_chain_register.</i></b>
<a name="L1385" href="source/drivers/cpufreq/cpufreq.c#L1385">1385</a> <b><i> */</i></b>
<a name="L1386" href="source/drivers/cpufreq/cpufreq.c#L1386">1386</a> int <a href="ident?i=cpufreq_register_notifier">cpufreq_register_notifier</a>(struct <a href="ident?i=notifier_block">notifier_block</a> *<a href="ident?i=nb">nb</a>, unsigned int <a href="ident?i=list">list</a>)
<a name="L1387" href="source/drivers/cpufreq/cpufreq.c#L1387">1387</a> {
<a name="L1388" href="source/drivers/cpufreq/cpufreq.c#L1388">1388</a>         int <a href="ident?i=ret">ret</a>;
<a name="L1389" href="source/drivers/cpufreq/cpufreq.c#L1389">1389</a> 
<a name="L1390" href="source/drivers/cpufreq/cpufreq.c#L1390">1390</a>         <a href="ident?i=WARN_ON">WARN_ON</a>(!<a href="ident?i=init_cpufreq_transition_notifier_list_called">init_cpufreq_transition_notifier_list_called</a>);
<a name="L1391" href="source/drivers/cpufreq/cpufreq.c#L1391">1391</a> 
<a name="L1392" href="source/drivers/cpufreq/cpufreq.c#L1392">1392</a>         switch (<a href="ident?i=list">list</a>) {
<a name="L1393" href="source/drivers/cpufreq/cpufreq.c#L1393">1393</a>         case <a href="ident?i=CPUFREQ_TRANSITION_NOTIFIER">CPUFREQ_TRANSITION_NOTIFIER</a>:
<a name="L1394" href="source/drivers/cpufreq/cpufreq.c#L1394">1394</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=srcu_notifier_chain_register">srcu_notifier_chain_register</a>(
<a name="L1395" href="source/drivers/cpufreq/cpufreq.c#L1395">1395</a>                                 &amp;<a href="ident?i=cpufreq_transition_notifier_list">cpufreq_transition_notifier_list</a>, <a href="ident?i=nb">nb</a>);
<a name="L1396" href="source/drivers/cpufreq/cpufreq.c#L1396">1396</a>                 break;
<a name="L1397" href="source/drivers/cpufreq/cpufreq.c#L1397">1397</a>         case <a href="ident?i=CPUFREQ_POLICY_NOTIFIER">CPUFREQ_POLICY_NOTIFIER</a>:
<a name="L1398" href="source/drivers/cpufreq/cpufreq.c#L1398">1398</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=blocking_notifier_chain_register">blocking_notifier_chain_register</a>(
<a name="L1399" href="source/drivers/cpufreq/cpufreq.c#L1399">1399</a>                                 &amp;cpufreq_policy_notifier_list, <a href="ident?i=nb">nb</a>);
<a name="L1400" href="source/drivers/cpufreq/cpufreq.c#L1400">1400</a>                 break;
<a name="L1401" href="source/drivers/cpufreq/cpufreq.c#L1401">1401</a>         default:
<a name="L1402" href="source/drivers/cpufreq/cpufreq.c#L1402">1402</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1403" href="source/drivers/cpufreq/cpufreq.c#L1403">1403</a>         }
<a name="L1404" href="source/drivers/cpufreq/cpufreq.c#L1404">1404</a> 
<a name="L1405" href="source/drivers/cpufreq/cpufreq.c#L1405">1405</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1406" href="source/drivers/cpufreq/cpufreq.c#L1406">1406</a> }
<a name="L1407" href="source/drivers/cpufreq/cpufreq.c#L1407">1407</a> <a href="ident?i=EXPORT_SYMBOL">EXPORT_SYMBOL</a>(<a href="ident?i=cpufreq_register_notifier">cpufreq_register_notifier</a>);
<a name="L1408" href="source/drivers/cpufreq/cpufreq.c#L1408">1408</a> 
<a name="L1409" href="source/drivers/cpufreq/cpufreq.c#L1409">1409</a> 
<a name="L1410" href="source/drivers/cpufreq/cpufreq.c#L1410">1410</a> <b><i>/**</i></b>
<a name="L1411" href="source/drivers/cpufreq/cpufreq.c#L1411">1411</a> <b><i> *      cpufreq_unregister_notifier - unregister a driver with cpufreq</i></b>
<a name="L1412" href="source/drivers/cpufreq/cpufreq.c#L1412">1412</a> <b><i> *      @nb: notifier block to be unregistered</i></b>
<a name="L1413" href="source/drivers/cpufreq/cpufreq.c#L1413">1413</a> <b><i> *      @list: CPUFREQ_TRANSITION_NOTIFIER or CPUFREQ_POLICY_NOTIFIER</i></b>
<a name="L1414" href="source/drivers/cpufreq/cpufreq.c#L1414">1414</a> <b><i> *</i></b>
<a name="L1415" href="source/drivers/cpufreq/cpufreq.c#L1415">1415</a> <b><i> *      Remove a driver from the CPU frequency notifier list.</i></b>
<a name="L1416" href="source/drivers/cpufreq/cpufreq.c#L1416">1416</a> <b><i> *</i></b>
<a name="L1417" href="source/drivers/cpufreq/cpufreq.c#L1417">1417</a> <b><i> *      This function may sleep, and has the same return conditions as</i></b>
<a name="L1418" href="source/drivers/cpufreq/cpufreq.c#L1418">1418</a> <b><i> *      blocking_notifier_chain_unregister.</i></b>
<a name="L1419" href="source/drivers/cpufreq/cpufreq.c#L1419">1419</a> <b><i> */</i></b>
<a name="L1420" href="source/drivers/cpufreq/cpufreq.c#L1420">1420</a> int <a href="ident?i=cpufreq_unregister_notifier">cpufreq_unregister_notifier</a>(struct <a href="ident?i=notifier_block">notifier_block</a> *<a href="ident?i=nb">nb</a>, unsigned int <a href="ident?i=list">list</a>)
<a name="L1421" href="source/drivers/cpufreq/cpufreq.c#L1421">1421</a> {
<a name="L1422" href="source/drivers/cpufreq/cpufreq.c#L1422">1422</a>         int <a href="ident?i=ret">ret</a>;
<a name="L1423" href="source/drivers/cpufreq/cpufreq.c#L1423">1423</a> 
<a name="L1424" href="source/drivers/cpufreq/cpufreq.c#L1424">1424</a>         switch (<a href="ident?i=list">list</a>) {
<a name="L1425" href="source/drivers/cpufreq/cpufreq.c#L1425">1425</a>         case <a href="ident?i=CPUFREQ_TRANSITION_NOTIFIER">CPUFREQ_TRANSITION_NOTIFIER</a>:
<a name="L1426" href="source/drivers/cpufreq/cpufreq.c#L1426">1426</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=srcu_notifier_chain_unregister">srcu_notifier_chain_unregister</a>(
<a name="L1427" href="source/drivers/cpufreq/cpufreq.c#L1427">1427</a>                                 &amp;<a href="ident?i=cpufreq_transition_notifier_list">cpufreq_transition_notifier_list</a>, <a href="ident?i=nb">nb</a>);
<a name="L1428" href="source/drivers/cpufreq/cpufreq.c#L1428">1428</a>                 break;
<a name="L1429" href="source/drivers/cpufreq/cpufreq.c#L1429">1429</a>         case <a href="ident?i=CPUFREQ_POLICY_NOTIFIER">CPUFREQ_POLICY_NOTIFIER</a>:
<a name="L1430" href="source/drivers/cpufreq/cpufreq.c#L1430">1430</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=blocking_notifier_chain_unregister">blocking_notifier_chain_unregister</a>(
<a name="L1431" href="source/drivers/cpufreq/cpufreq.c#L1431">1431</a>                                 &amp;cpufreq_policy_notifier_list, <a href="ident?i=nb">nb</a>);
<a name="L1432" href="source/drivers/cpufreq/cpufreq.c#L1432">1432</a>                 break;
<a name="L1433" href="source/drivers/cpufreq/cpufreq.c#L1433">1433</a>         default:
<a name="L1434" href="source/drivers/cpufreq/cpufreq.c#L1434">1434</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1435" href="source/drivers/cpufreq/cpufreq.c#L1435">1435</a>         }
<a name="L1436" href="source/drivers/cpufreq/cpufreq.c#L1436">1436</a> 
<a name="L1437" href="source/drivers/cpufreq/cpufreq.c#L1437">1437</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1438" href="source/drivers/cpufreq/cpufreq.c#L1438">1438</a> }
<a name="L1439" href="source/drivers/cpufreq/cpufreq.c#L1439">1439</a> <a href="ident?i=EXPORT_SYMBOL">EXPORT_SYMBOL</a>(<a href="ident?i=cpufreq_unregister_notifier">cpufreq_unregister_notifier</a>);
<a name="L1440" href="source/drivers/cpufreq/cpufreq.c#L1440">1440</a> 
<a name="L1441" href="source/drivers/cpufreq/cpufreq.c#L1441">1441</a> 
<a name="L1442" href="source/drivers/cpufreq/cpufreq.c#L1442">1442</a> <b><i>/*********************************************************************</i></b>
<a name="L1443" href="source/drivers/cpufreq/cpufreq.c#L1443">1443</a> <b><i> *                              GOVERNORS                            *</i></b>
<a name="L1444" href="source/drivers/cpufreq/cpufreq.c#L1444">1444</a> <b><i> *********************************************************************/</i></b>
<a name="L1445" href="source/drivers/cpufreq/cpufreq.c#L1445">1445</a> 
<a name="L1446" href="source/drivers/cpufreq/cpufreq.c#L1446">1446</a> 
<a name="L1447" href="source/drivers/cpufreq/cpufreq.c#L1447">1447</a> int <a href="ident?i=__cpufreq_driver_target">__cpufreq_driver_target</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy,
<a name="L1448" href="source/drivers/cpufreq/cpufreq.c#L1448">1448</a>                             unsigned int target_freq,
<a name="L1449" href="source/drivers/cpufreq/cpufreq.c#L1449">1449</a>                             unsigned int relation)
<a name="L1450" href="source/drivers/cpufreq/cpufreq.c#L1450">1450</a> {
<a name="L1451" href="source/drivers/cpufreq/cpufreq.c#L1451">1451</a>         int retval = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1452" href="source/drivers/cpufreq/cpufreq.c#L1452">1452</a> 
<a name="L1453" href="source/drivers/cpufreq/cpufreq.c#L1453">1453</a>         if (<a href="ident?i=cpufreq_disabled">cpufreq_disabled</a>())
<a name="L1454" href="source/drivers/cpufreq/cpufreq.c#L1454">1454</a>                 return -<a href="ident?i=ENODEV">ENODEV</a>;
<a name="L1455" href="source/drivers/cpufreq/cpufreq.c#L1455">1455</a> 
<a name="L1456" href="source/drivers/cpufreq/cpufreq.c#L1456">1456</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"target for CPU %u: %u kHz, relation %u\n"</i>, policy-&gt;<a href="ident?i=cpu">cpu</a>,
<a name="L1457" href="source/drivers/cpufreq/cpufreq.c#L1457">1457</a>                 target_freq, relation);
<a name="L1458" href="source/drivers/cpufreq/cpufreq.c#L1458">1458</a>         if (<a href="ident?i=cpu_online">cpu_online</a>(policy-&gt;<a href="ident?i=cpu">cpu</a>) &amp;&amp; <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=target">target</a>)
<a name="L1459" href="source/drivers/cpufreq/cpufreq.c#L1459">1459</a>                 retval = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=target">target</a>(policy, target_freq, relation);
<a name="L1460" href="source/drivers/cpufreq/cpufreq.c#L1460">1460</a> 
<a name="L1461" href="source/drivers/cpufreq/cpufreq.c#L1461">1461</a>         return retval;
<a name="L1462" href="source/drivers/cpufreq/cpufreq.c#L1462">1462</a> }
<a name="L1463" href="source/drivers/cpufreq/cpufreq.c#L1463">1463</a> <a href="ident?i=EXPORT_SYMBOL_GPL">EXPORT_SYMBOL_GPL</a>(<a href="ident?i=__cpufreq_driver_target">__cpufreq_driver_target</a>);
<a name="L1464" href="source/drivers/cpufreq/cpufreq.c#L1464">1464</a> 
<a name="L1465" href="source/drivers/cpufreq/cpufreq.c#L1465">1465</a> int <a href="ident?i=cpufreq_driver_target">cpufreq_driver_target</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy,
<a name="L1466" href="source/drivers/cpufreq/cpufreq.c#L1466">1466</a>                           unsigned int target_freq,
<a name="L1467" href="source/drivers/cpufreq/cpufreq.c#L1467">1467</a>                           unsigned int relation)
<a name="L1468" href="source/drivers/cpufreq/cpufreq.c#L1468">1468</a> {
<a name="L1469" href="source/drivers/cpufreq/cpufreq.c#L1469">1469</a>         int <a href="ident?i=ret">ret</a> = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1470" href="source/drivers/cpufreq/cpufreq.c#L1470">1470</a> 
<a name="L1471" href="source/drivers/cpufreq/cpufreq.c#L1471">1471</a>         policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(policy-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L1472" href="source/drivers/cpufreq/cpufreq.c#L1472">1472</a>         if (!policy)
<a name="L1473" href="source/drivers/cpufreq/cpufreq.c#L1473">1473</a>                 goto no_policy;
<a name="L1474" href="source/drivers/cpufreq/cpufreq.c#L1474">1474</a> 
<a name="L1475" href="source/drivers/cpufreq/cpufreq.c#L1475">1475</a>         if (<a href="ident?i=unlikely">unlikely</a>(lock_policy_rwsem_write(policy-&gt;<a href="ident?i=cpu">cpu</a>)))
<a name="L1476" href="source/drivers/cpufreq/cpufreq.c#L1476">1476</a>                 goto fail;
<a name="L1477" href="source/drivers/cpufreq/cpufreq.c#L1477">1477</a> 
<a name="L1478" href="source/drivers/cpufreq/cpufreq.c#L1478">1478</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=__cpufreq_driver_target">__cpufreq_driver_target</a>(policy, target_freq, relation);
<a name="L1479" href="source/drivers/cpufreq/cpufreq.c#L1479">1479</a> 
<a name="L1480" href="source/drivers/cpufreq/cpufreq.c#L1480">1480</a>         <a href="ident?i=unlock_policy_rwsem_write">unlock_policy_rwsem_write</a>(policy-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L1481" href="source/drivers/cpufreq/cpufreq.c#L1481">1481</a> 
<a name="L1482" href="source/drivers/cpufreq/cpufreq.c#L1482">1482</a> fail:
<a name="L1483" href="source/drivers/cpufreq/cpufreq.c#L1483">1483</a>         <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(policy);
<a name="L1484" href="source/drivers/cpufreq/cpufreq.c#L1484">1484</a> no_policy:
<a name="L1485" href="source/drivers/cpufreq/cpufreq.c#L1485">1485</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1486" href="source/drivers/cpufreq/cpufreq.c#L1486">1486</a> }
<a name="L1487" href="source/drivers/cpufreq/cpufreq.c#L1487">1487</a> <a href="ident?i=EXPORT_SYMBOL_GPL">EXPORT_SYMBOL_GPL</a>(<a href="ident?i=cpufreq_driver_target">cpufreq_driver_target</a>);
<a name="L1488" href="source/drivers/cpufreq/cpufreq.c#L1488">1488</a> 
<a name="L1489" href="source/drivers/cpufreq/cpufreq.c#L1489">1489</a> int <a href="ident?i=__cpufreq_driver_getavg">__cpufreq_driver_getavg</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy, unsigned int <a href="ident?i=cpu">cpu</a>)
<a name="L1490" href="source/drivers/cpufreq/cpufreq.c#L1490">1490</a> {
<a name="L1491" href="source/drivers/cpufreq/cpufreq.c#L1491">1491</a>         int <a href="ident?i=ret">ret</a> = 0;
<a name="L1492" href="source/drivers/cpufreq/cpufreq.c#L1492">1492</a> 
<a name="L1493" href="source/drivers/cpufreq/cpufreq.c#L1493">1493</a>         policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(policy-&gt;<a href="ident?i=cpu">cpu</a>);
<a name="L1494" href="source/drivers/cpufreq/cpufreq.c#L1494">1494</a>         if (!policy)
<a name="L1495" href="source/drivers/cpufreq/cpufreq.c#L1495">1495</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1496" href="source/drivers/cpufreq/cpufreq.c#L1496">1496</a> 
<a name="L1497" href="source/drivers/cpufreq/cpufreq.c#L1497">1497</a>         if (<a href="ident?i=cpu_online">cpu_online</a>(<a href="ident?i=cpu">cpu</a>) &amp;&amp; <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;getavg)
<a name="L1498" href="source/drivers/cpufreq/cpufreq.c#L1498">1498</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;getavg(policy, <a href="ident?i=cpu">cpu</a>);
<a name="L1499" href="source/drivers/cpufreq/cpufreq.c#L1499">1499</a> 
<a name="L1500" href="source/drivers/cpufreq/cpufreq.c#L1500">1500</a>         <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(policy);
<a name="L1501" href="source/drivers/cpufreq/cpufreq.c#L1501">1501</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1502" href="source/drivers/cpufreq/cpufreq.c#L1502">1502</a> }
<a name="L1503" href="source/drivers/cpufreq/cpufreq.c#L1503">1503</a> <a href="ident?i=EXPORT_SYMBOL_GPL">EXPORT_SYMBOL_GPL</a>(<a href="ident?i=__cpufreq_driver_getavg">__cpufreq_driver_getavg</a>);
<a name="L1504" href="source/drivers/cpufreq/cpufreq.c#L1504">1504</a> 
<a name="L1505" href="source/drivers/cpufreq/cpufreq.c#L1505">1505</a> <b><i>/*</i></b>
<a name="L1506" href="source/drivers/cpufreq/cpufreq.c#L1506">1506</a> <b><i> * when "event" is CPUFREQ_GOV_LIMITS</i></b>
<a name="L1507" href="source/drivers/cpufreq/cpufreq.c#L1507">1507</a> <b><i> */</i></b>
<a name="L1508" href="source/drivers/cpufreq/cpufreq.c#L1508">1508</a> 
<a name="L1509" href="source/drivers/cpufreq/cpufreq.c#L1509">1509</a> static int <a href="ident?i=__cpufreq_governor">__cpufreq_governor</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy,
<a name="L1510" href="source/drivers/cpufreq/cpufreq.c#L1510">1510</a>                                         unsigned int <a href="ident?i=event">event</a>)
<a name="L1511" href="source/drivers/cpufreq/cpufreq.c#L1511">1511</a> {
<a name="L1512" href="source/drivers/cpufreq/cpufreq.c#L1512">1512</a>         int <a href="ident?i=ret">ret</a>;
<a name="L1513" href="source/drivers/cpufreq/cpufreq.c#L1513">1513</a> 
<a name="L1514" href="source/drivers/cpufreq/cpufreq.c#L1514">1514</a>         <b><i>/* Only must be defined when default governor is known to have latency</i></b>
<a name="L1515" href="source/drivers/cpufreq/cpufreq.c#L1515">1515</a> <b><i>           restrictions, like e.g. conservative or ondemand.</i></b>
<a name="L1516" href="source/drivers/cpufreq/cpufreq.c#L1516">1516</a> <b><i>           That this is the case is already ensured in Kconfig</i></b>
<a name="L1517" href="source/drivers/cpufreq/cpufreq.c#L1517">1517</a> <b><i>        */</i></b>
<a name="L1518" href="source/drivers/cpufreq/cpufreq.c#L1518">1518</a> #ifdef CONFIG_CPU_FREQ_GOV_PERFORMANCE
<a name="L1519" href="source/drivers/cpufreq/cpufreq.c#L1519">1519</a>         struct <a href="ident?i=cpufreq_governor">cpufreq_governor</a> *gov = &amp;<a href="ident?i=cpufreq_gov_performance">cpufreq_gov_performance</a>;
<a name="L1520" href="source/drivers/cpufreq/cpufreq.c#L1520">1520</a> #else
<a name="L1521" href="source/drivers/cpufreq/cpufreq.c#L1521">1521</a>         struct <a href="ident?i=cpufreq_governor">cpufreq_governor</a> *gov = <a href="ident?i=NULL">NULL</a>;
<a name="L1522" href="source/drivers/cpufreq/cpufreq.c#L1522">1522</a> #endif
<a name="L1523" href="source/drivers/cpufreq/cpufreq.c#L1523">1523</a> 
<a name="L1524" href="source/drivers/cpufreq/cpufreq.c#L1524">1524</a>         if (policy-&gt;governor-&gt;max_transition_latency &amp;&amp;
<a name="L1525" href="source/drivers/cpufreq/cpufreq.c#L1525">1525</a>             policy-&gt;<a href="ident?i=cpuinfo">cpuinfo</a>.<a href="ident?i=transition_latency">transition_latency</a> &gt;
<a name="L1526" href="source/drivers/cpufreq/cpufreq.c#L1526">1526</a>             policy-&gt;governor-&gt;max_transition_latency) {
<a name="L1527" href="source/drivers/cpufreq/cpufreq.c#L1527">1527</a>                 if (!gov)
<a name="L1528" href="source/drivers/cpufreq/cpufreq.c#L1528">1528</a>                         return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1529" href="source/drivers/cpufreq/cpufreq.c#L1529">1529</a>                 else {
<a name="L1530" href="source/drivers/cpufreq/cpufreq.c#L1530">1530</a>                         <a href="ident?i=printk">printk</a>(<a href="ident?i=KERN_WARNING">KERN_WARNING</a> <i>"%s governor failed, too long"</i>
<a name="L1531" href="source/drivers/cpufreq/cpufreq.c#L1531">1531</a>                                <i>" transition latency of HW, fallback"</i>
<a name="L1532" href="source/drivers/cpufreq/cpufreq.c#L1532">1532</a>                                <i>" to %s governor\n"</i>,
<a name="L1533" href="source/drivers/cpufreq/cpufreq.c#L1533">1533</a>                                policy-&gt;governor-&gt;<a href="ident?i=name">name</a>,
<a name="L1534" href="source/drivers/cpufreq/cpufreq.c#L1534">1534</a>                                gov-&gt;<a href="ident?i=name">name</a>);
<a name="L1535" href="source/drivers/cpufreq/cpufreq.c#L1535">1535</a>                         policy-&gt;governor = gov;
<a name="L1536" href="source/drivers/cpufreq/cpufreq.c#L1536">1536</a>                 }
<a name="L1537" href="source/drivers/cpufreq/cpufreq.c#L1537">1537</a>         }
<a name="L1538" href="source/drivers/cpufreq/cpufreq.c#L1538">1538</a> 
<a name="L1539" href="source/drivers/cpufreq/cpufreq.c#L1539">1539</a>         if (!<a href="ident?i=try_module_get">try_module_get</a>(policy-&gt;governor-&gt;owner))
<a name="L1540" href="source/drivers/cpufreq/cpufreq.c#L1540">1540</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1541" href="source/drivers/cpufreq/cpufreq.c#L1541">1541</a> 
<a name="L1542" href="source/drivers/cpufreq/cpufreq.c#L1542">1542</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"__cpufreq_governor for CPU %u, event %u\n"</i>,
<a name="L1543" href="source/drivers/cpufreq/cpufreq.c#L1543">1543</a>                                                 policy-&gt;<a href="ident?i=cpu">cpu</a>, <a href="ident?i=event">event</a>);
<a name="L1544" href="source/drivers/cpufreq/cpufreq.c#L1544">1544</a>         <a href="ident?i=ret">ret</a> = policy-&gt;governor-&gt;governor(policy, <a href="ident?i=event">event</a>);
<a name="L1545" href="source/drivers/cpufreq/cpufreq.c#L1545">1545</a> 
<a name="L1546" href="source/drivers/cpufreq/cpufreq.c#L1546">1546</a>         <b><i>/* we keep one module reference alive for</i></b>
<a name="L1547" href="source/drivers/cpufreq/cpufreq.c#L1547">1547</a> <b><i>                        each CPU governed by this CPU */</i></b>
<a name="L1548" href="source/drivers/cpufreq/cpufreq.c#L1548">1548</a>         if ((<a href="ident?i=event">event</a> != <a href="ident?i=CPUFREQ_GOV_START">CPUFREQ_GOV_START</a>) || <a href="ident?i=ret">ret</a>)
<a name="L1549" href="source/drivers/cpufreq/cpufreq.c#L1549">1549</a>                 <a href="ident?i=module_put">module_put</a>(policy-&gt;governor-&gt;owner);
<a name="L1550" href="source/drivers/cpufreq/cpufreq.c#L1550">1550</a>         if ((<a href="ident?i=event">event</a> == <a href="ident?i=CPUFREQ_GOV_STOP">CPUFREQ_GOV_STOP</a>) &amp;&amp; !<a href="ident?i=ret">ret</a>)
<a name="L1551" href="source/drivers/cpufreq/cpufreq.c#L1551">1551</a>                 <a href="ident?i=module_put">module_put</a>(policy-&gt;governor-&gt;owner);
<a name="L1552" href="source/drivers/cpufreq/cpufreq.c#L1552">1552</a> 
<a name="L1553" href="source/drivers/cpufreq/cpufreq.c#L1553">1553</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1554" href="source/drivers/cpufreq/cpufreq.c#L1554">1554</a> }
<a name="L1555" href="source/drivers/cpufreq/cpufreq.c#L1555">1555</a> 
<a name="L1556" href="source/drivers/cpufreq/cpufreq.c#L1556">1556</a> 
<a name="L1557" href="source/drivers/cpufreq/cpufreq.c#L1557">1557</a> int <a href="ident?i=cpufreq_register_governor">cpufreq_register_governor</a>(struct <a href="ident?i=cpufreq_governor">cpufreq_governor</a> *governor)
<a name="L1558" href="source/drivers/cpufreq/cpufreq.c#L1558">1558</a> {
<a name="L1559" href="source/drivers/cpufreq/cpufreq.c#L1559">1559</a>         int <a href="ident?i=err">err</a>;
<a name="L1560" href="source/drivers/cpufreq/cpufreq.c#L1560">1560</a> 
<a name="L1561" href="source/drivers/cpufreq/cpufreq.c#L1561">1561</a>         if (!governor)
<a name="L1562" href="source/drivers/cpufreq/cpufreq.c#L1562">1562</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1563" href="source/drivers/cpufreq/cpufreq.c#L1563">1563</a> 
<a name="L1564" href="source/drivers/cpufreq/cpufreq.c#L1564">1564</a>         if (<a href="ident?i=cpufreq_disabled">cpufreq_disabled</a>())
<a name="L1565" href="source/drivers/cpufreq/cpufreq.c#L1565">1565</a>                 return -<a href="ident?i=ENODEV">ENODEV</a>;
<a name="L1566" href="source/drivers/cpufreq/cpufreq.c#L1566">1566</a> 
<a name="L1567" href="source/drivers/cpufreq/cpufreq.c#L1567">1567</a>         <a href="ident?i=mutex_lock">mutex_lock</a>(&amp;cpufreq_governor_mutex);
<a name="L1568" href="source/drivers/cpufreq/cpufreq.c#L1568">1568</a> 
<a name="L1569" href="source/drivers/cpufreq/cpufreq.c#L1569">1569</a>         <a href="ident?i=err">err</a> = -<a href="ident?i=EBUSY">EBUSY</a>;
<a name="L1570" href="source/drivers/cpufreq/cpufreq.c#L1570">1570</a>         if (<a href="ident?i=__find_governor">__find_governor</a>(governor-&gt;<a href="ident?i=name">name</a>) == <a href="ident?i=NULL">NULL</a>) {
<a name="L1571" href="source/drivers/cpufreq/cpufreq.c#L1571">1571</a>                 <a href="ident?i=err">err</a> = 0;
<a name="L1572" href="source/drivers/cpufreq/cpufreq.c#L1572">1572</a>                 <a href="ident?i=list_add">list_add</a>(&amp;governor-&gt;governor_list, &amp;cpufreq_governor_list);
<a name="L1573" href="source/drivers/cpufreq/cpufreq.c#L1573">1573</a>         }
<a name="L1574" href="source/drivers/cpufreq/cpufreq.c#L1574">1574</a> 
<a name="L1575" href="source/drivers/cpufreq/cpufreq.c#L1575">1575</a>         <a href="ident?i=mutex_unlock">mutex_unlock</a>(&amp;cpufreq_governor_mutex);
<a name="L1576" href="source/drivers/cpufreq/cpufreq.c#L1576">1576</a>         return <a href="ident?i=err">err</a>;
<a name="L1577" href="source/drivers/cpufreq/cpufreq.c#L1577">1577</a> }
<a name="L1578" href="source/drivers/cpufreq/cpufreq.c#L1578">1578</a> <a href="ident?i=EXPORT_SYMBOL_GPL">EXPORT_SYMBOL_GPL</a>(<a href="ident?i=cpufreq_register_governor">cpufreq_register_governor</a>);
<a name="L1579" href="source/drivers/cpufreq/cpufreq.c#L1579">1579</a> 
<a name="L1580" href="source/drivers/cpufreq/cpufreq.c#L1580">1580</a> 
<a name="L1581" href="source/drivers/cpufreq/cpufreq.c#L1581">1581</a> void <a href="ident?i=cpufreq_unregister_governor">cpufreq_unregister_governor</a>(struct <a href="ident?i=cpufreq_governor">cpufreq_governor</a> *governor)
<a name="L1582" href="source/drivers/cpufreq/cpufreq.c#L1582">1582</a> {
<a name="L1583" href="source/drivers/cpufreq/cpufreq.c#L1583">1583</a> #ifdef CONFIG_HOTPLUG_CPU
<a name="L1584" href="source/drivers/cpufreq/cpufreq.c#L1584">1584</a>         int <a href="ident?i=cpu">cpu</a>;
<a name="L1585" href="source/drivers/cpufreq/cpufreq.c#L1585">1585</a> #endif
<a name="L1586" href="source/drivers/cpufreq/cpufreq.c#L1586">1586</a> 
<a name="L1587" href="source/drivers/cpufreq/cpufreq.c#L1587">1587</a>         if (!governor)
<a name="L1588" href="source/drivers/cpufreq/cpufreq.c#L1588">1588</a>                 return;
<a name="L1589" href="source/drivers/cpufreq/cpufreq.c#L1589">1589</a> 
<a name="L1590" href="source/drivers/cpufreq/cpufreq.c#L1590">1590</a>         if (<a href="ident?i=cpufreq_disabled">cpufreq_disabled</a>())
<a name="L1591" href="source/drivers/cpufreq/cpufreq.c#L1591">1591</a>                 return;
<a name="L1592" href="source/drivers/cpufreq/cpufreq.c#L1592">1592</a> 
<a name="L1593" href="source/drivers/cpufreq/cpufreq.c#L1593">1593</a> #ifdef CONFIG_HOTPLUG_CPU
<a name="L1594" href="source/drivers/cpufreq/cpufreq.c#L1594">1594</a>         <a href="ident?i=for_each_present_cpu">for_each_present_cpu</a>(<a href="ident?i=cpu">cpu</a>) {
<a name="L1595" href="source/drivers/cpufreq/cpufreq.c#L1595">1595</a>                 if (<a href="ident?i=cpu_online">cpu_online</a>(<a href="ident?i=cpu">cpu</a>))
<a name="L1596" href="source/drivers/cpufreq/cpufreq.c#L1596">1596</a>                         continue;
<a name="L1597" href="source/drivers/cpufreq/cpufreq.c#L1597">1597</a>                 if (!<a href="ident?i=strcmp">strcmp</a>(<a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_governor, <a href="ident?i=cpu">cpu</a>), governor-&gt;<a href="ident?i=name">name</a>))
<a name="L1598" href="source/drivers/cpufreq/cpufreq.c#L1598">1598</a>                         <a href="ident?i=strcpy">strcpy</a>(<a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_governor, <a href="ident?i=cpu">cpu</a>), <i>"\0"</i>);
<a name="L1599" href="source/drivers/cpufreq/cpufreq.c#L1599">1599</a>         }
<a name="L1600" href="source/drivers/cpufreq/cpufreq.c#L1600">1600</a> #endif
<a name="L1601" href="source/drivers/cpufreq/cpufreq.c#L1601">1601</a> 
<a name="L1602" href="source/drivers/cpufreq/cpufreq.c#L1602">1602</a>         <a href="ident?i=mutex_lock">mutex_lock</a>(&amp;cpufreq_governor_mutex);
<a name="L1603" href="source/drivers/cpufreq/cpufreq.c#L1603">1603</a>         <a href="ident?i=list_del">list_del</a>(&amp;governor-&gt;governor_list);
<a name="L1604" href="source/drivers/cpufreq/cpufreq.c#L1604">1604</a>         <a href="ident?i=mutex_unlock">mutex_unlock</a>(&amp;cpufreq_governor_mutex);
<a name="L1605" href="source/drivers/cpufreq/cpufreq.c#L1605">1605</a>         return;
<a name="L1606" href="source/drivers/cpufreq/cpufreq.c#L1606">1606</a> }
<a name="L1607" href="source/drivers/cpufreq/cpufreq.c#L1607">1607</a> <a href="ident?i=EXPORT_SYMBOL_GPL">EXPORT_SYMBOL_GPL</a>(<a href="ident?i=cpufreq_unregister_governor">cpufreq_unregister_governor</a>);
<a name="L1608" href="source/drivers/cpufreq/cpufreq.c#L1608">1608</a> 
<a name="L1609" href="source/drivers/cpufreq/cpufreq.c#L1609">1609</a> 
<a name="L1610" href="source/drivers/cpufreq/cpufreq.c#L1610">1610</a> 
<a name="L1611" href="source/drivers/cpufreq/cpufreq.c#L1611">1611</a> <b><i>/*********************************************************************</i></b>
<a name="L1612" href="source/drivers/cpufreq/cpufreq.c#L1612">1612</a> <b><i> *                          POLICY INTERFACE                         *</i></b>
<a name="L1613" href="source/drivers/cpufreq/cpufreq.c#L1613">1613</a> <b><i> *********************************************************************/</i></b>
<a name="L1614" href="source/drivers/cpufreq/cpufreq.c#L1614">1614</a> 
<a name="L1615" href="source/drivers/cpufreq/cpufreq.c#L1615">1615</a> <b><i>/**</i></b>
<a name="L1616" href="source/drivers/cpufreq/cpufreq.c#L1616">1616</a> <b><i> * cpufreq_get_policy - get the current cpufreq_policy</i></b>
<a name="L1617" href="source/drivers/cpufreq/cpufreq.c#L1617">1617</a> <b><i> * @policy: struct cpufreq_policy into which the current cpufreq_policy</i></b>
<a name="L1618" href="source/drivers/cpufreq/cpufreq.c#L1618">1618</a> <b><i> *      is written</i></b>
<a name="L1619" href="source/drivers/cpufreq/cpufreq.c#L1619">1619</a> <b><i> *</i></b>
<a name="L1620" href="source/drivers/cpufreq/cpufreq.c#L1620">1620</a> <b><i> * Reads the current cpufreq policy.</i></b>
<a name="L1621" href="source/drivers/cpufreq/cpufreq.c#L1621">1621</a> <b><i> */</i></b>
<a name="L1622" href="source/drivers/cpufreq/cpufreq.c#L1622">1622</a> int <a href="ident?i=cpufreq_get_policy">cpufreq_get_policy</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy, unsigned int <a href="ident?i=cpu">cpu</a>)
<a name="L1623" href="source/drivers/cpufreq/cpufreq.c#L1623">1623</a> {
<a name="L1624" href="source/drivers/cpufreq/cpufreq.c#L1624">1624</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *cpu_policy;
<a name="L1625" href="source/drivers/cpufreq/cpufreq.c#L1625">1625</a>         if (!policy)
<a name="L1626" href="source/drivers/cpufreq/cpufreq.c#L1626">1626</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1627" href="source/drivers/cpufreq/cpufreq.c#L1627">1627</a> 
<a name="L1628" href="source/drivers/cpufreq/cpufreq.c#L1628">1628</a>         cpu_policy = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1629" href="source/drivers/cpufreq/cpufreq.c#L1629">1629</a>         if (!cpu_policy)
<a name="L1630" href="source/drivers/cpufreq/cpufreq.c#L1630">1630</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1631" href="source/drivers/cpufreq/cpufreq.c#L1631">1631</a> 
<a name="L1632" href="source/drivers/cpufreq/cpufreq.c#L1632">1632</a>         <a href="ident?i=memcpy">memcpy</a>(policy, cpu_policy, sizeof(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a>));
<a name="L1633" href="source/drivers/cpufreq/cpufreq.c#L1633">1633</a> 
<a name="L1634" href="source/drivers/cpufreq/cpufreq.c#L1634">1634</a>         <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(cpu_policy);
<a name="L1635" href="source/drivers/cpufreq/cpufreq.c#L1635">1635</a>         return 0;
<a name="L1636" href="source/drivers/cpufreq/cpufreq.c#L1636">1636</a> }
<a name="L1637" href="source/drivers/cpufreq/cpufreq.c#L1637">1637</a> <a href="ident?i=EXPORT_SYMBOL">EXPORT_SYMBOL</a>(<a href="ident?i=cpufreq_get_policy">cpufreq_get_policy</a>);
<a name="L1638" href="source/drivers/cpufreq/cpufreq.c#L1638">1638</a> 
<a name="L1639" href="source/drivers/cpufreq/cpufreq.c#L1639">1639</a> 
<a name="L1640" href="source/drivers/cpufreq/cpufreq.c#L1640">1640</a> <b><i>/*</i></b>
<a name="L1641" href="source/drivers/cpufreq/cpufreq.c#L1641">1641</a> <b><i> * data   : current policy.</i></b>
<a name="L1642" href="source/drivers/cpufreq/cpufreq.c#L1642">1642</a> <b><i> * policy : policy to be set.</i></b>
<a name="L1643" href="source/drivers/cpufreq/cpufreq.c#L1643">1643</a> <b><i> */</i></b>
<a name="L1644" href="source/drivers/cpufreq/cpufreq.c#L1644">1644</a> static int <a href="ident?i=__cpufreq_set_policy">__cpufreq_set_policy</a>(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *<a href="ident?i=data">data</a>,
<a name="L1645" href="source/drivers/cpufreq/cpufreq.c#L1645">1645</a>                                 struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *policy)
<a name="L1646" href="source/drivers/cpufreq/cpufreq.c#L1646">1646</a> {
<a name="L1647" href="source/drivers/cpufreq/cpufreq.c#L1647">1647</a>         int <a href="ident?i=ret">ret</a> = 0;
<a name="L1648" href="source/drivers/cpufreq/cpufreq.c#L1648">1648</a> 
<a name="L1649" href="source/drivers/cpufreq/cpufreq.c#L1649">1649</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"setting new policy for CPU %u: %u - %u kHz\n"</i>, policy-&gt;<a href="ident?i=cpu">cpu</a>,
<a name="L1650" href="source/drivers/cpufreq/cpufreq.c#L1650">1650</a>                 policy-&gt;<a href="ident?i=min">min</a>, policy-&gt;<a href="ident?i=max">max</a>);
<a name="L1651" href="source/drivers/cpufreq/cpufreq.c#L1651">1651</a> 
<a name="L1652" href="source/drivers/cpufreq/cpufreq.c#L1652">1652</a>         <a href="ident?i=memcpy">memcpy</a>(&amp;policy-&gt;<a href="ident?i=cpuinfo">cpuinfo</a>, &amp;<a href="ident?i=data">data</a>-&gt;<a href="ident?i=cpuinfo">cpuinfo</a>,
<a name="L1653" href="source/drivers/cpufreq/cpufreq.c#L1653">1653</a>                                 sizeof(struct <a href="ident?i=cpufreq_cpuinfo">cpufreq_cpuinfo</a>));
<a name="L1654" href="source/drivers/cpufreq/cpufreq.c#L1654">1654</a> 
<a name="L1655" href="source/drivers/cpufreq/cpufreq.c#L1655">1655</a>         if (policy-&gt;<a href="ident?i=min">min</a> &gt; <a href="ident?i=data">data</a>-&gt;<a href="ident?i=max">max</a> || policy-&gt;<a href="ident?i=max">max</a> &lt; <a href="ident?i=data">data</a>-&gt;<a href="ident?i=min">min</a>) {
<a name="L1656" href="source/drivers/cpufreq/cpufreq.c#L1656">1656</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1657" href="source/drivers/cpufreq/cpufreq.c#L1657">1657</a>                 goto error_out;
<a name="L1658" href="source/drivers/cpufreq/cpufreq.c#L1658">1658</a>         }
<a name="L1659" href="source/drivers/cpufreq/cpufreq.c#L1659">1659</a> 
<a name="L1660" href="source/drivers/cpufreq/cpufreq.c#L1660">1660</a>         <b><i>/* verify the cpu speed can be set within this limit */</i></b>
<a name="L1661" href="source/drivers/cpufreq/cpufreq.c#L1661">1661</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=verify">verify</a>(policy);
<a name="L1662" href="source/drivers/cpufreq/cpufreq.c#L1662">1662</a>         if (<a href="ident?i=ret">ret</a>)
<a name="L1663" href="source/drivers/cpufreq/cpufreq.c#L1663">1663</a>                 goto error_out;
<a name="L1664" href="source/drivers/cpufreq/cpufreq.c#L1664">1664</a> 
<a name="L1665" href="source/drivers/cpufreq/cpufreq.c#L1665">1665</a>         <b><i>/* adjust if necessary - all reasons */</i></b>
<a name="L1666" href="source/drivers/cpufreq/cpufreq.c#L1666">1666</a>         <a href="ident?i=blocking_notifier_call_chain">blocking_notifier_call_chain</a>(&amp;cpufreq_policy_notifier_list,
<a name="L1667" href="source/drivers/cpufreq/cpufreq.c#L1667">1667</a>                         <a href="ident?i=CPUFREQ_ADJUST">CPUFREQ_ADJUST</a>, policy);
<a name="L1668" href="source/drivers/cpufreq/cpufreq.c#L1668">1668</a> 
<a name="L1669" href="source/drivers/cpufreq/cpufreq.c#L1669">1669</a>         <b><i>/* adjust if necessary - hardware incompatibility*/</i></b>
<a name="L1670" href="source/drivers/cpufreq/cpufreq.c#L1670">1670</a>         <a href="ident?i=blocking_notifier_call_chain">blocking_notifier_call_chain</a>(&amp;cpufreq_policy_notifier_list,
<a name="L1671" href="source/drivers/cpufreq/cpufreq.c#L1671">1671</a>                         <a href="ident?i=CPUFREQ_INCOMPATIBLE">CPUFREQ_INCOMPATIBLE</a>, policy);
<a name="L1672" href="source/drivers/cpufreq/cpufreq.c#L1672">1672</a> 
<a name="L1673" href="source/drivers/cpufreq/cpufreq.c#L1673">1673</a>         <b><i>/* verify the cpu speed can be set within this limit,</i></b>
<a name="L1674" href="source/drivers/cpufreq/cpufreq.c#L1674">1674</a> <b><i>           which might be different to the first one */</i></b>
<a name="L1675" href="source/drivers/cpufreq/cpufreq.c#L1675">1675</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=verify">verify</a>(policy);
<a name="L1676" href="source/drivers/cpufreq/cpufreq.c#L1676">1676</a>         if (<a href="ident?i=ret">ret</a>)
<a name="L1677" href="source/drivers/cpufreq/cpufreq.c#L1677">1677</a>                 goto error_out;
<a name="L1678" href="source/drivers/cpufreq/cpufreq.c#L1678">1678</a> 
<a name="L1679" href="source/drivers/cpufreq/cpufreq.c#L1679">1679</a>         <b><i>/* notification of the new policy */</i></b>
<a name="L1680" href="source/drivers/cpufreq/cpufreq.c#L1680">1680</a>         <a href="ident?i=blocking_notifier_call_chain">blocking_notifier_call_chain</a>(&amp;cpufreq_policy_notifier_list,
<a name="L1681" href="source/drivers/cpufreq/cpufreq.c#L1681">1681</a>                         <a href="ident?i=CPUFREQ_NOTIFY">CPUFREQ_NOTIFY</a>, policy);
<a name="L1682" href="source/drivers/cpufreq/cpufreq.c#L1682">1682</a> 
<a name="L1683" href="source/drivers/cpufreq/cpufreq.c#L1683">1683</a>         <a href="ident?i=data">data</a>-&gt;<a href="ident?i=min">min</a> = policy-&gt;<a href="ident?i=min">min</a>;
<a name="L1684" href="source/drivers/cpufreq/cpufreq.c#L1684">1684</a>         <a href="ident?i=data">data</a>-&gt;<a href="ident?i=max">max</a> = policy-&gt;<a href="ident?i=max">max</a>;
<a name="L1685" href="source/drivers/cpufreq/cpufreq.c#L1685">1685</a> 
<a name="L1686" href="source/drivers/cpufreq/cpufreq.c#L1686">1686</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"new min and max freqs are %u - %u kHz\n"</i>,
<a name="L1687" href="source/drivers/cpufreq/cpufreq.c#L1687">1687</a>                                         <a href="ident?i=data">data</a>-&gt;<a href="ident?i=min">min</a>, <a href="ident?i=data">data</a>-&gt;<a href="ident?i=max">max</a>);
<a name="L1688" href="source/drivers/cpufreq/cpufreq.c#L1688">1688</a> 
<a name="L1689" href="source/drivers/cpufreq/cpufreq.c#L1689">1689</a>         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;setpolicy) {
<a name="L1690" href="source/drivers/cpufreq/cpufreq.c#L1690">1690</a>                 <a href="ident?i=data">data</a>-&gt;policy = policy-&gt;policy;
<a name="L1691" href="source/drivers/cpufreq/cpufreq.c#L1691">1691</a>                 <a href="ident?i=pr_debug">pr_debug</a>(<i>"setting range\n"</i>);
<a name="L1692" href="source/drivers/cpufreq/cpufreq.c#L1692">1692</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;setpolicy(policy);
<a name="L1693" href="source/drivers/cpufreq/cpufreq.c#L1693">1693</a>         } else {
<a name="L1694" href="source/drivers/cpufreq/cpufreq.c#L1694">1694</a>                 if (policy-&gt;governor != <a href="ident?i=data">data</a>-&gt;governor) {
<a name="L1695" href="source/drivers/cpufreq/cpufreq.c#L1695">1695</a>                         <b><i>/* save old, working values */</i></b>
<a name="L1696" href="source/drivers/cpufreq/cpufreq.c#L1696">1696</a>                         struct <a href="ident?i=cpufreq_governor">cpufreq_governor</a> *old_gov = <a href="ident?i=data">data</a>-&gt;governor;
<a name="L1697" href="source/drivers/cpufreq/cpufreq.c#L1697">1697</a> 
<a name="L1698" href="source/drivers/cpufreq/cpufreq.c#L1698">1698</a>                         <a href="ident?i=pr_debug">pr_debug</a>(<i>"governor switch\n"</i>);
<a name="L1699" href="source/drivers/cpufreq/cpufreq.c#L1699">1699</a> 
<a name="L1700" href="source/drivers/cpufreq/cpufreq.c#L1700">1700</a>                         <b><i>/* end old governor */</i></b>
<a name="L1701" href="source/drivers/cpufreq/cpufreq.c#L1701">1701</a>                         if (<a href="ident?i=data">data</a>-&gt;governor)
<a name="L1702" href="source/drivers/cpufreq/cpufreq.c#L1702">1702</a>                                 <a href="ident?i=__cpufreq_governor">__cpufreq_governor</a>(<a href="ident?i=data">data</a>, <a href="ident?i=CPUFREQ_GOV_STOP">CPUFREQ_GOV_STOP</a>);
<a name="L1703" href="source/drivers/cpufreq/cpufreq.c#L1703">1703</a> 
<a name="L1704" href="source/drivers/cpufreq/cpufreq.c#L1704">1704</a>                         <b><i>/* start new governor */</i></b>
<a name="L1705" href="source/drivers/cpufreq/cpufreq.c#L1705">1705</a>                         <a href="ident?i=data">data</a>-&gt;governor = policy-&gt;governor;
<a name="L1706" href="source/drivers/cpufreq/cpufreq.c#L1706">1706</a>                         if (<a href="ident?i=__cpufreq_governor">__cpufreq_governor</a>(<a href="ident?i=data">data</a>, <a href="ident?i=CPUFREQ_GOV_START">CPUFREQ_GOV_START</a>)) {
<a name="L1707" href="source/drivers/cpufreq/cpufreq.c#L1707">1707</a>                                 <b><i>/* new governor failed, so re-start old one */</i></b>
<a name="L1708" href="source/drivers/cpufreq/cpufreq.c#L1708">1708</a>                                 <a href="ident?i=pr_debug">pr_debug</a>(<i>"starting governor %s failed\n"</i>,
<a name="L1709" href="source/drivers/cpufreq/cpufreq.c#L1709">1709</a>                                                         <a href="ident?i=data">data</a>-&gt;governor-&gt;<a href="ident?i=name">name</a>);
<a name="L1710" href="source/drivers/cpufreq/cpufreq.c#L1710">1710</a>                                 if (old_gov) {
<a name="L1711" href="source/drivers/cpufreq/cpufreq.c#L1711">1711</a>                                         <a href="ident?i=data">data</a>-&gt;governor = old_gov;
<a name="L1712" href="source/drivers/cpufreq/cpufreq.c#L1712">1712</a>                                         <a href="ident?i=__cpufreq_governor">__cpufreq_governor</a>(<a href="ident?i=data">data</a>,
<a name="L1713" href="source/drivers/cpufreq/cpufreq.c#L1713">1713</a>                                                            <a href="ident?i=CPUFREQ_GOV_START">CPUFREQ_GOV_START</a>);
<a name="L1714" href="source/drivers/cpufreq/cpufreq.c#L1714">1714</a>                                 }
<a name="L1715" href="source/drivers/cpufreq/cpufreq.c#L1715">1715</a>                                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1716" href="source/drivers/cpufreq/cpufreq.c#L1716">1716</a>                                 goto error_out;
<a name="L1717" href="source/drivers/cpufreq/cpufreq.c#L1717">1717</a>                         }
<a name="L1718" href="source/drivers/cpufreq/cpufreq.c#L1718">1718</a>                         <b><i>/* might be a policy change, too, so fall through */</i></b>
<a name="L1719" href="source/drivers/cpufreq/cpufreq.c#L1719">1719</a>                 }
<a name="L1720" href="source/drivers/cpufreq/cpufreq.c#L1720">1720</a>                 <a href="ident?i=pr_debug">pr_debug</a>(<i>"governor: change or update limits\n"</i>);
<a name="L1721" href="source/drivers/cpufreq/cpufreq.c#L1721">1721</a>                 <a href="ident?i=__cpufreq_governor">__cpufreq_governor</a>(<a href="ident?i=data">data</a>, <a href="ident?i=CPUFREQ_GOV_LIMITS">CPUFREQ_GOV_LIMITS</a>);
<a name="L1722" href="source/drivers/cpufreq/cpufreq.c#L1722">1722</a>         }
<a name="L1723" href="source/drivers/cpufreq/cpufreq.c#L1723">1723</a> 
<a name="L1724" href="source/drivers/cpufreq/cpufreq.c#L1724">1724</a> error_out:
<a name="L1725" href="source/drivers/cpufreq/cpufreq.c#L1725">1725</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1726" href="source/drivers/cpufreq/cpufreq.c#L1726">1726</a> }
<a name="L1727" href="source/drivers/cpufreq/cpufreq.c#L1727">1727</a> 
<a name="L1728" href="source/drivers/cpufreq/cpufreq.c#L1728">1728</a> <b><i>/**</i></b>
<a name="L1729" href="source/drivers/cpufreq/cpufreq.c#L1729">1729</a> <b><i> *      cpufreq_update_policy - re-evaluate an existing cpufreq policy</i></b>
<a name="L1730" href="source/drivers/cpufreq/cpufreq.c#L1730">1730</a> <b><i> *      @cpu: CPU which shall be re-evaluated</i></b>
<a name="L1731" href="source/drivers/cpufreq/cpufreq.c#L1731">1731</a> <b><i> *</i></b>
<a name="L1732" href="source/drivers/cpufreq/cpufreq.c#L1732">1732</a> <b><i> *      Useful for policy notifiers which have different necessities</i></b>
<a name="L1733" href="source/drivers/cpufreq/cpufreq.c#L1733">1733</a> <b><i> *      at different times.</i></b>
<a name="L1734" href="source/drivers/cpufreq/cpufreq.c#L1734">1734</a> <b><i> */</i></b>
<a name="L1735" href="source/drivers/cpufreq/cpufreq.c#L1735">1735</a> int <a href="ident?i=cpufreq_update_policy">cpufreq_update_policy</a>(unsigned int <a href="ident?i=cpu">cpu</a>)
<a name="L1736" href="source/drivers/cpufreq/cpufreq.c#L1736">1736</a> {
<a name="L1737" href="source/drivers/cpufreq/cpufreq.c#L1737">1737</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> *<a href="ident?i=data">data</a> = <a href="ident?i=cpufreq_cpu_get">cpufreq_cpu_get</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1738" href="source/drivers/cpufreq/cpufreq.c#L1738">1738</a>         struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a> policy;
<a name="L1739" href="source/drivers/cpufreq/cpufreq.c#L1739">1739</a>         int <a href="ident?i=ret">ret</a>;
<a name="L1740" href="source/drivers/cpufreq/cpufreq.c#L1740">1740</a> 
<a name="L1741" href="source/drivers/cpufreq/cpufreq.c#L1741">1741</a>         if (!<a href="ident?i=data">data</a>) {
<a name="L1742" href="source/drivers/cpufreq/cpufreq.c#L1742">1742</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=ENODEV">ENODEV</a>;
<a name="L1743" href="source/drivers/cpufreq/cpufreq.c#L1743">1743</a>                 goto no_policy;
<a name="L1744" href="source/drivers/cpufreq/cpufreq.c#L1744">1744</a>         }
<a name="L1745" href="source/drivers/cpufreq/cpufreq.c#L1745">1745</a> 
<a name="L1746" href="source/drivers/cpufreq/cpufreq.c#L1746">1746</a>         if (<a href="ident?i=unlikely">unlikely</a>(lock_policy_rwsem_write(<a href="ident?i=cpu">cpu</a>))) {
<a name="L1747" href="source/drivers/cpufreq/cpufreq.c#L1747">1747</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1748" href="source/drivers/cpufreq/cpufreq.c#L1748">1748</a>                 goto fail;
<a name="L1749" href="source/drivers/cpufreq/cpufreq.c#L1749">1749</a>         }
<a name="L1750" href="source/drivers/cpufreq/cpufreq.c#L1750">1750</a> 
<a name="L1751" href="source/drivers/cpufreq/cpufreq.c#L1751">1751</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"updating policy for CPU %u\n"</i>, <a href="ident?i=cpu">cpu</a>);
<a name="L1752" href="source/drivers/cpufreq/cpufreq.c#L1752">1752</a>         <a href="ident?i=memcpy">memcpy</a>(&amp;policy, <a href="ident?i=data">data</a>, sizeof(struct <a href="ident?i=cpufreq_policy">cpufreq_policy</a>));
<a name="L1753" href="source/drivers/cpufreq/cpufreq.c#L1753">1753</a>         policy.<a href="ident?i=min">min</a> = <a href="ident?i=data">data</a>-&gt;user_policy.<a href="ident?i=min">min</a>;
<a name="L1754" href="source/drivers/cpufreq/cpufreq.c#L1754">1754</a>         policy.<a href="ident?i=max">max</a> = <a href="ident?i=data">data</a>-&gt;user_policy.<a href="ident?i=max">max</a>;
<a name="L1755" href="source/drivers/cpufreq/cpufreq.c#L1755">1755</a>         policy.policy = <a href="ident?i=data">data</a>-&gt;user_policy.policy;
<a name="L1756" href="source/drivers/cpufreq/cpufreq.c#L1756">1756</a>         policy.governor = <a href="ident?i=data">data</a>-&gt;user_policy.governor;
<a name="L1757" href="source/drivers/cpufreq/cpufreq.c#L1757">1757</a> 
<a name="L1758" href="source/drivers/cpufreq/cpufreq.c#L1758">1758</a>         <b><i>/* BIOS might change freq behind our back</i></b>
<a name="L1759" href="source/drivers/cpufreq/cpufreq.c#L1759">1759</a> <b><i>          -&gt; ask driver for current freq and notify governors about a change */</i></b>
<a name="L1760" href="source/drivers/cpufreq/cpufreq.c#L1760">1760</a>         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=get">get</a>) {
<a name="L1761" href="source/drivers/cpufreq/cpufreq.c#L1761">1761</a>                 policy.cur = <a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=get">get</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1762" href="source/drivers/cpufreq/cpufreq.c#L1762">1762</a>                 if (!<a href="ident?i=data">data</a>-&gt;cur) {
<a name="L1763" href="source/drivers/cpufreq/cpufreq.c#L1763">1763</a>                         <a href="ident?i=pr_debug">pr_debug</a>(<i>"Driver did not initialize current freq"</i>);
<a name="L1764" href="source/drivers/cpufreq/cpufreq.c#L1764">1764</a>                         <a href="ident?i=data">data</a>-&gt;cur = policy.cur;
<a name="L1765" href="source/drivers/cpufreq/cpufreq.c#L1765">1765</a>                 } else {
<a name="L1766" href="source/drivers/cpufreq/cpufreq.c#L1766">1766</a>                         if (<a href="ident?i=data">data</a>-&gt;cur != policy.cur)
<a name="L1767" href="source/drivers/cpufreq/cpufreq.c#L1767">1767</a>                                 <a href="ident?i=cpufreq_out_of_sync">cpufreq_out_of_sync</a>(<a href="ident?i=cpu">cpu</a>, <a href="ident?i=data">data</a>-&gt;cur,
<a name="L1768" href="source/drivers/cpufreq/cpufreq.c#L1768">1768</a>                                                                 policy.cur);
<a name="L1769" href="source/drivers/cpufreq/cpufreq.c#L1769">1769</a>                 }
<a name="L1770" href="source/drivers/cpufreq/cpufreq.c#L1770">1770</a>         }
<a name="L1771" href="source/drivers/cpufreq/cpufreq.c#L1771">1771</a> 
<a name="L1772" href="source/drivers/cpufreq/cpufreq.c#L1772">1772</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=__cpufreq_set_policy">__cpufreq_set_policy</a>(<a href="ident?i=data">data</a>, &amp;policy);
<a name="L1773" href="source/drivers/cpufreq/cpufreq.c#L1773">1773</a> 
<a name="L1774" href="source/drivers/cpufreq/cpufreq.c#L1774">1774</a>         <a href="ident?i=unlock_policy_rwsem_write">unlock_policy_rwsem_write</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1775" href="source/drivers/cpufreq/cpufreq.c#L1775">1775</a> 
<a name="L1776" href="source/drivers/cpufreq/cpufreq.c#L1776">1776</a> fail:
<a name="L1777" href="source/drivers/cpufreq/cpufreq.c#L1777">1777</a>         <a href="ident?i=cpufreq_cpu_put">cpufreq_cpu_put</a>(<a href="ident?i=data">data</a>);
<a name="L1778" href="source/drivers/cpufreq/cpufreq.c#L1778">1778</a> no_policy:
<a name="L1779" href="source/drivers/cpufreq/cpufreq.c#L1779">1779</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1780" href="source/drivers/cpufreq/cpufreq.c#L1780">1780</a> }
<a name="L1781" href="source/drivers/cpufreq/cpufreq.c#L1781">1781</a> <a href="ident?i=EXPORT_SYMBOL">EXPORT_SYMBOL</a>(<a href="ident?i=cpufreq_update_policy">cpufreq_update_policy</a>);
<a name="L1782" href="source/drivers/cpufreq/cpufreq.c#L1782">1782</a> 
<a name="L1783" href="source/drivers/cpufreq/cpufreq.c#L1783">1783</a> static int <a href="ident?i=__cpuinit">__cpuinit</a> <a href="ident?i=cpufreq_cpu_callback">cpufreq_cpu_callback</a>(struct <a href="ident?i=notifier_block">notifier_block</a> *nfb,
<a name="L1784" href="source/drivers/cpufreq/cpufreq.c#L1784">1784</a>                                         unsigned long <a href="ident?i=action">action</a>, void *hcpu)
<a name="L1785" href="source/drivers/cpufreq/cpufreq.c#L1785">1785</a> {
<a name="L1786" href="source/drivers/cpufreq/cpufreq.c#L1786">1786</a>         unsigned int <a href="ident?i=cpu">cpu</a> = (unsigned long)hcpu;
<a name="L1787" href="source/drivers/cpufreq/cpufreq.c#L1787">1787</a>         struct <a href="ident?i=device">device</a> *<a href="ident?i=dev">dev</a>;
<a name="L1788" href="source/drivers/cpufreq/cpufreq.c#L1788">1788</a> 
<a name="L1789" href="source/drivers/cpufreq/cpufreq.c#L1789">1789</a>         <a href="ident?i=dev">dev</a> = <a href="ident?i=get_cpu_device">get_cpu_device</a>(<a href="ident?i=cpu">cpu</a>);
<a name="L1790" href="source/drivers/cpufreq/cpufreq.c#L1790">1790</a>         if (<a href="ident?i=dev">dev</a>) {
<a name="L1791" href="source/drivers/cpufreq/cpufreq.c#L1791">1791</a>                 switch (<a href="ident?i=action">action</a>) {
<a name="L1792" href="source/drivers/cpufreq/cpufreq.c#L1792">1792</a>                 case <a href="ident?i=CPU_ONLINE">CPU_ONLINE</a>:
<a name="L1793" href="source/drivers/cpufreq/cpufreq.c#L1793">1793</a>                 case <a href="ident?i=CPU_ONLINE_FROZEN">CPU_ONLINE_FROZEN</a>:
<a name="L1794" href="source/drivers/cpufreq/cpufreq.c#L1794">1794</a>                         <a href="ident?i=cpufreq_add_dev">cpufreq_add_dev</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=NULL">NULL</a>);
<a name="L1795" href="source/drivers/cpufreq/cpufreq.c#L1795">1795</a>                         break;
<a name="L1796" href="source/drivers/cpufreq/cpufreq.c#L1796">1796</a>                 case <a href="ident?i=CPU_DOWN_PREPARE">CPU_DOWN_PREPARE</a>:
<a name="L1797" href="source/drivers/cpufreq/cpufreq.c#L1797">1797</a>                 case <a href="ident?i=CPU_DOWN_PREPARE_FROZEN">CPU_DOWN_PREPARE_FROZEN</a>:
<a name="L1798" href="source/drivers/cpufreq/cpufreq.c#L1798">1798</a>                         if (<a href="ident?i=unlikely">unlikely</a>(lock_policy_rwsem_write(<a href="ident?i=cpu">cpu</a>)))
<a name="L1799" href="source/drivers/cpufreq/cpufreq.c#L1799">1799</a>                                 <a href="ident?i=BUG">BUG</a>();
<a name="L1800" href="source/drivers/cpufreq/cpufreq.c#L1800">1800</a> 
<a name="L1801" href="source/drivers/cpufreq/cpufreq.c#L1801">1801</a>                         <a href="ident?i=__cpufreq_remove_dev">__cpufreq_remove_dev</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=NULL">NULL</a>);
<a name="L1802" href="source/drivers/cpufreq/cpufreq.c#L1802">1802</a>                         break;
<a name="L1803" href="source/drivers/cpufreq/cpufreq.c#L1803">1803</a>                 case <a href="ident?i=CPU_DOWN_FAILED">CPU_DOWN_FAILED</a>:
<a name="L1804" href="source/drivers/cpufreq/cpufreq.c#L1804">1804</a>                 case <a href="ident?i=CPU_DOWN_FAILED_FROZEN">CPU_DOWN_FAILED_FROZEN</a>:
<a name="L1805" href="source/drivers/cpufreq/cpufreq.c#L1805">1805</a>                         <a href="ident?i=cpufreq_add_dev">cpufreq_add_dev</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=NULL">NULL</a>);
<a name="L1806" href="source/drivers/cpufreq/cpufreq.c#L1806">1806</a>                         break;
<a name="L1807" href="source/drivers/cpufreq/cpufreq.c#L1807">1807</a>                 }
<a name="L1808" href="source/drivers/cpufreq/cpufreq.c#L1808">1808</a>         }
<a name="L1809" href="source/drivers/cpufreq/cpufreq.c#L1809">1809</a>         return <a href="ident?i=NOTIFY_OK">NOTIFY_OK</a>;
<a name="L1810" href="source/drivers/cpufreq/cpufreq.c#L1810">1810</a> }
<a name="L1811" href="source/drivers/cpufreq/cpufreq.c#L1811">1811</a> 
<a name="L1812" href="source/drivers/cpufreq/cpufreq.c#L1812">1812</a> static struct <a href="ident?i=notifier_block">notifier_block</a> <a href="ident?i=__refdata">__refdata</a> <a href="ident?i=cpufreq_cpu_notifier">cpufreq_cpu_notifier</a> = {
<a name="L1813" href="source/drivers/cpufreq/cpufreq.c#L1813">1813</a>     .notifier_call = <a href="ident?i=cpufreq_cpu_callback">cpufreq_cpu_callback</a>,
<a name="L1814" href="source/drivers/cpufreq/cpufreq.c#L1814">1814</a> };
<a name="L1815" href="source/drivers/cpufreq/cpufreq.c#L1815">1815</a> 
<a name="L1816" href="source/drivers/cpufreq/cpufreq.c#L1816">1816</a> <b><i>/*********************************************************************</i></b>
<a name="L1817" href="source/drivers/cpufreq/cpufreq.c#L1817">1817</a> <b><i> *               REGISTER / UNREGISTER CPUFREQ DRIVER                *</i></b>
<a name="L1818" href="source/drivers/cpufreq/cpufreq.c#L1818">1818</a> <b><i> *********************************************************************/</i></b>
<a name="L1819" href="source/drivers/cpufreq/cpufreq.c#L1819">1819</a> 
<a name="L1820" href="source/drivers/cpufreq/cpufreq.c#L1820">1820</a> <b><i>/**</i></b>
<a name="L1821" href="source/drivers/cpufreq/cpufreq.c#L1821">1821</a> <b><i> * cpufreq_register_driver - register a CPU Frequency driver</i></b>
<a name="L1822" href="source/drivers/cpufreq/cpufreq.c#L1822">1822</a> <b><i> * @driver_data: A struct cpufreq_driver containing the values#</i></b>
<a name="L1823" href="source/drivers/cpufreq/cpufreq.c#L1823">1823</a> <b><i> * submitted by the CPU Frequency driver.</i></b>
<a name="L1824" href="source/drivers/cpufreq/cpufreq.c#L1824">1824</a> <b><i> *</i></b>
<a name="L1825" href="source/drivers/cpufreq/cpufreq.c#L1825">1825</a> <b><i> *   Registers a CPU Frequency driver to this core code. This code</i></b>
<a name="L1826" href="source/drivers/cpufreq/cpufreq.c#L1826">1826</a> <b><i> * returns zero on success, -EBUSY when another driver got here first</i></b>
<a name="L1827" href="source/drivers/cpufreq/cpufreq.c#L1827">1827</a> <b><i> * (and isn't unregistered in the meantime).</i></b>
<a name="L1828" href="source/drivers/cpufreq/cpufreq.c#L1828">1828</a> <b><i> *</i></b>
<a name="L1829" href="source/drivers/cpufreq/cpufreq.c#L1829">1829</a> <b><i> */</i></b>
<a name="L1830" href="source/drivers/cpufreq/cpufreq.c#L1830">1830</a> int <a href="ident?i=cpufreq_register_driver">cpufreq_register_driver</a>(struct <a href="ident?i=cpufreq_driver">cpufreq_driver</a> *<a href="ident?i=driver_data">driver_data</a>)
<a name="L1831" href="source/drivers/cpufreq/cpufreq.c#L1831">1831</a> {
<a name="L1832" href="source/drivers/cpufreq/cpufreq.c#L1832">1832</a>         unsigned long <a href="ident?i=flags">flags</a>;
<a name="L1833" href="source/drivers/cpufreq/cpufreq.c#L1833">1833</a>         int <a href="ident?i=ret">ret</a>;
<a name="L1834" href="source/drivers/cpufreq/cpufreq.c#L1834">1834</a> 
<a name="L1835" href="source/drivers/cpufreq/cpufreq.c#L1835">1835</a>         if (<a href="ident?i=cpufreq_disabled">cpufreq_disabled</a>())
<a name="L1836" href="source/drivers/cpufreq/cpufreq.c#L1836">1836</a>                 return -<a href="ident?i=ENODEV">ENODEV</a>;
<a name="L1837" href="source/drivers/cpufreq/cpufreq.c#L1837">1837</a> 
<a name="L1838" href="source/drivers/cpufreq/cpufreq.c#L1838">1838</a>         if (!<a href="ident?i=driver_data">driver_data</a> || !<a href="ident?i=driver_data">driver_data</a>-&gt;<a href="ident?i=verify">verify</a> || !<a href="ident?i=driver_data">driver_data</a>-&gt;<a href="ident?i=init">init</a> ||
<a name="L1839" href="source/drivers/cpufreq/cpufreq.c#L1839">1839</a>             ((!<a href="ident?i=driver_data">driver_data</a>-&gt;setpolicy) &amp;&amp; (!<a href="ident?i=driver_data">driver_data</a>-&gt;<a href="ident?i=target">target</a>)))
<a name="L1840" href="source/drivers/cpufreq/cpufreq.c#L1840">1840</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1841" href="source/drivers/cpufreq/cpufreq.c#L1841">1841</a> 
<a name="L1842" href="source/drivers/cpufreq/cpufreq.c#L1842">1842</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"trying to register driver %s\n"</i>, <a href="ident?i=driver_data">driver_data</a>-&gt;<a href="ident?i=name">name</a>);
<a name="L1843" href="source/drivers/cpufreq/cpufreq.c#L1843">1843</a> 
<a name="L1844" href="source/drivers/cpufreq/cpufreq.c#L1844">1844</a>         if (<a href="ident?i=driver_data">driver_data</a>-&gt;setpolicy)
<a name="L1845" href="source/drivers/cpufreq/cpufreq.c#L1845">1845</a>                 <a href="ident?i=driver_data">driver_data</a>-&gt;<a href="ident?i=flags">flags</a> |= <a href="ident?i=CPUFREQ_CONST_LOOPS">CPUFREQ_CONST_LOOPS</a>;
<a name="L1846" href="source/drivers/cpufreq/cpufreq.c#L1846">1846</a> 
<a name="L1847" href="source/drivers/cpufreq/cpufreq.c#L1847">1847</a>         <a href="ident?i=spin_lock_irqsave">spin_lock_irqsave</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L1848" href="source/drivers/cpufreq/cpufreq.c#L1848">1848</a>         if (<a href="ident?i=cpufreq_driver">cpufreq_driver</a>) {
<a name="L1849" href="source/drivers/cpufreq/cpufreq.c#L1849">1849</a>                 <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L1850" href="source/drivers/cpufreq/cpufreq.c#L1850">1850</a>                 return -<a href="ident?i=EBUSY">EBUSY</a>;
<a name="L1851" href="source/drivers/cpufreq/cpufreq.c#L1851">1851</a>         }
<a name="L1852" href="source/drivers/cpufreq/cpufreq.c#L1852">1852</a>         <a href="ident?i=cpufreq_driver">cpufreq_driver</a> = <a href="ident?i=driver_data">driver_data</a>;
<a name="L1853" href="source/drivers/cpufreq/cpufreq.c#L1853">1853</a>         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L1854" href="source/drivers/cpufreq/cpufreq.c#L1854">1854</a> 
<a name="L1855" href="source/drivers/cpufreq/cpufreq.c#L1855">1855</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=subsys_interface_register">subsys_interface_register</a>(&amp;<a href="ident?i=cpufreq_interface">cpufreq_interface</a>);
<a name="L1856" href="source/drivers/cpufreq/cpufreq.c#L1856">1856</a>         if (<a href="ident?i=ret">ret</a>)
<a name="L1857" href="source/drivers/cpufreq/cpufreq.c#L1857">1857</a>                 goto err_null_driver;
<a name="L1858" href="source/drivers/cpufreq/cpufreq.c#L1858">1858</a> 
<a name="L1859" href="source/drivers/cpufreq/cpufreq.c#L1859">1859</a>         if (!(<a href="ident?i=cpufreq_driver">cpufreq_driver</a>-&gt;<a href="ident?i=flags">flags</a> &amp; <a href="ident?i=CPUFREQ_STICKY">CPUFREQ_STICKY</a>)) {
<a name="L1860" href="source/drivers/cpufreq/cpufreq.c#L1860">1860</a>                 int <a href="ident?i=i">i</a>;
<a name="L1861" href="source/drivers/cpufreq/cpufreq.c#L1861">1861</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=ENODEV">ENODEV</a>;
<a name="L1862" href="source/drivers/cpufreq/cpufreq.c#L1862">1862</a> 
<a name="L1863" href="source/drivers/cpufreq/cpufreq.c#L1863">1863</a>                 <b><i>/* check for at least one working CPU */</i></b>
<a name="L1864" href="source/drivers/cpufreq/cpufreq.c#L1864">1864</a>                 for (<a href="ident?i=i">i</a> = 0; <a href="ident?i=i">i</a> &lt; <a href="ident?i=nr_cpu_ids">nr_cpu_ids</a>; <a href="ident?i=i">i</a>++)
<a name="L1865" href="source/drivers/cpufreq/cpufreq.c#L1865">1865</a>                         if (<a href="ident?i=cpu_possible">cpu_possible</a>(<a href="ident?i=i">i</a>) &amp;&amp; <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_cpu_data, <a href="ident?i=i">i</a>)) {
<a name="L1866" href="source/drivers/cpufreq/cpufreq.c#L1866">1866</a>                                 <a href="ident?i=ret">ret</a> = 0;
<a name="L1867" href="source/drivers/cpufreq/cpufreq.c#L1867">1867</a>                                 break;
<a name="L1868" href="source/drivers/cpufreq/cpufreq.c#L1868">1868</a>                         }
<a name="L1869" href="source/drivers/cpufreq/cpufreq.c#L1869">1869</a> 
<a name="L1870" href="source/drivers/cpufreq/cpufreq.c#L1870">1870</a>                 <b><i>/* if all -&gt;init() calls failed, unregister */</i></b>
<a name="L1871" href="source/drivers/cpufreq/cpufreq.c#L1871">1871</a>                 if (<a href="ident?i=ret">ret</a>) {
<a name="L1872" href="source/drivers/cpufreq/cpufreq.c#L1872">1872</a>                         <a href="ident?i=pr_debug">pr_debug</a>(<i>"no CPU initialized for driver %s\n"</i>,
<a name="L1873" href="source/drivers/cpufreq/cpufreq.c#L1873">1873</a>                                                         <a href="ident?i=driver_data">driver_data</a>-&gt;<a href="ident?i=name">name</a>);
<a name="L1874" href="source/drivers/cpufreq/cpufreq.c#L1874">1874</a>                         goto err_if_unreg;
<a name="L1875" href="source/drivers/cpufreq/cpufreq.c#L1875">1875</a>                 }
<a name="L1876" href="source/drivers/cpufreq/cpufreq.c#L1876">1876</a>         }
<a name="L1877" href="source/drivers/cpufreq/cpufreq.c#L1877">1877</a> 
<a name="L1878" href="source/drivers/cpufreq/cpufreq.c#L1878">1878</a>         <a href="ident?i=register_hotcpu_notifier">register_hotcpu_notifier</a>(&amp;<a href="ident?i=cpufreq_cpu_notifier">cpufreq_cpu_notifier</a>);
<a name="L1879" href="source/drivers/cpufreq/cpufreq.c#L1879">1879</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"driver %s up and running\n"</i>, <a href="ident?i=driver_data">driver_data</a>-&gt;<a href="ident?i=name">name</a>);
<a name="L1880" href="source/drivers/cpufreq/cpufreq.c#L1880">1880</a> 
<a name="L1881" href="source/drivers/cpufreq/cpufreq.c#L1881">1881</a>         return 0;
<a name="L1882" href="source/drivers/cpufreq/cpufreq.c#L1882">1882</a> err_if_unreg:
<a name="L1883" href="source/drivers/cpufreq/cpufreq.c#L1883">1883</a>         <a href="ident?i=subsys_interface_unregister">subsys_interface_unregister</a>(&amp;<a href="ident?i=cpufreq_interface">cpufreq_interface</a>);
<a name="L1884" href="source/drivers/cpufreq/cpufreq.c#L1884">1884</a> err_null_driver:
<a name="L1885" href="source/drivers/cpufreq/cpufreq.c#L1885">1885</a>         <a href="ident?i=spin_lock_irqsave">spin_lock_irqsave</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L1886" href="source/drivers/cpufreq/cpufreq.c#L1886">1886</a>         <a href="ident?i=cpufreq_driver">cpufreq_driver</a> = <a href="ident?i=NULL">NULL</a>;
<a name="L1887" href="source/drivers/cpufreq/cpufreq.c#L1887">1887</a>         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L1888" href="source/drivers/cpufreq/cpufreq.c#L1888">1888</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1889" href="source/drivers/cpufreq/cpufreq.c#L1889">1889</a> }
<a name="L1890" href="source/drivers/cpufreq/cpufreq.c#L1890">1890</a> <a href="ident?i=EXPORT_SYMBOL_GPL">EXPORT_SYMBOL_GPL</a>(<a href="ident?i=cpufreq_register_driver">cpufreq_register_driver</a>);
<a name="L1891" href="source/drivers/cpufreq/cpufreq.c#L1891">1891</a> 
<a name="L1892" href="source/drivers/cpufreq/cpufreq.c#L1892">1892</a> 
<a name="L1893" href="source/drivers/cpufreq/cpufreq.c#L1893">1893</a> <b><i>/**</i></b>
<a name="L1894" href="source/drivers/cpufreq/cpufreq.c#L1894">1894</a> <b><i> * cpufreq_unregister_driver - unregister the current CPUFreq driver</i></b>
<a name="L1895" href="source/drivers/cpufreq/cpufreq.c#L1895">1895</a> <b><i> *</i></b>
<a name="L1896" href="source/drivers/cpufreq/cpufreq.c#L1896">1896</a> <b><i> *    Unregister the current CPUFreq driver. Only call this if you have</i></b>
<a name="L1897" href="source/drivers/cpufreq/cpufreq.c#L1897">1897</a> <b><i> * the right to do so, i.e. if you have succeeded in initialising before!</i></b>
<a name="L1898" href="source/drivers/cpufreq/cpufreq.c#L1898">1898</a> <b><i> * Returns zero if successful, and -EINVAL if the cpufreq_driver is</i></b>
<a name="L1899" href="source/drivers/cpufreq/cpufreq.c#L1899">1899</a> <b><i> * currently not initialised.</i></b>
<a name="L1900" href="source/drivers/cpufreq/cpufreq.c#L1900">1900</a> <b><i> */</i></b>
<a name="L1901" href="source/drivers/cpufreq/cpufreq.c#L1901">1901</a> int <a href="ident?i=cpufreq_unregister_driver">cpufreq_unregister_driver</a>(struct <a href="ident?i=cpufreq_driver">cpufreq_driver</a> *<a href="ident?i=driver">driver</a>)
<a name="L1902" href="source/drivers/cpufreq/cpufreq.c#L1902">1902</a> {
<a name="L1903" href="source/drivers/cpufreq/cpufreq.c#L1903">1903</a>         unsigned long <a href="ident?i=flags">flags</a>;
<a name="L1904" href="source/drivers/cpufreq/cpufreq.c#L1904">1904</a> 
<a name="L1905" href="source/drivers/cpufreq/cpufreq.c#L1905">1905</a>         if (!<a href="ident?i=cpufreq_driver">cpufreq_driver</a> || (<a href="ident?i=driver">driver</a> != <a href="ident?i=cpufreq_driver">cpufreq_driver</a>))
<a name="L1906" href="source/drivers/cpufreq/cpufreq.c#L1906">1906</a>                 return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1907" href="source/drivers/cpufreq/cpufreq.c#L1907">1907</a> 
<a name="L1908" href="source/drivers/cpufreq/cpufreq.c#L1908">1908</a>         <a href="ident?i=pr_debug">pr_debug</a>(<i>"unregistering driver %s\n"</i>, <a href="ident?i=driver">driver</a>-&gt;<a href="ident?i=name">name</a>);
<a name="L1909" href="source/drivers/cpufreq/cpufreq.c#L1909">1909</a> 
<a name="L1910" href="source/drivers/cpufreq/cpufreq.c#L1910">1910</a>         <a href="ident?i=subsys_interface_unregister">subsys_interface_unregister</a>(&amp;<a href="ident?i=cpufreq_interface">cpufreq_interface</a>);
<a name="L1911" href="source/drivers/cpufreq/cpufreq.c#L1911">1911</a>         <a href="ident?i=unregister_hotcpu_notifier">unregister_hotcpu_notifier</a>(&amp;<a href="ident?i=cpufreq_cpu_notifier">cpufreq_cpu_notifier</a>);
<a name="L1912" href="source/drivers/cpufreq/cpufreq.c#L1912">1912</a> 
<a name="L1913" href="source/drivers/cpufreq/cpufreq.c#L1913">1913</a>         <a href="ident?i=spin_lock_irqsave">spin_lock_irqsave</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L1914" href="source/drivers/cpufreq/cpufreq.c#L1914">1914</a>         <a href="ident?i=cpufreq_driver">cpufreq_driver</a> = <a href="ident?i=NULL">NULL</a>;
<a name="L1915" href="source/drivers/cpufreq/cpufreq.c#L1915">1915</a>         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;cpufreq_driver_lock, <a href="ident?i=flags">flags</a>);
<a name="L1916" href="source/drivers/cpufreq/cpufreq.c#L1916">1916</a> 
<a name="L1917" href="source/drivers/cpufreq/cpufreq.c#L1917">1917</a>         return 0;
<a name="L1918" href="source/drivers/cpufreq/cpufreq.c#L1918">1918</a> }
<a name="L1919" href="source/drivers/cpufreq/cpufreq.c#L1919">1919</a> <a href="ident?i=EXPORT_SYMBOL_GPL">EXPORT_SYMBOL_GPL</a>(<a href="ident?i=cpufreq_unregister_driver">cpufreq_unregister_driver</a>);
<a name="L1920" href="source/drivers/cpufreq/cpufreq.c#L1920">1920</a> 
<a name="L1921" href="source/drivers/cpufreq/cpufreq.c#L1921">1921</a> static int <a href="ident?i=__init">__init</a> <a href="ident?i=cpufreq_core_init">cpufreq_core_init</a>(void)
<a name="L1922" href="source/drivers/cpufreq/cpufreq.c#L1922">1922</a> {
<a name="L1923" href="source/drivers/cpufreq/cpufreq.c#L1923">1923</a>         int <a href="ident?i=cpu">cpu</a>;
<a name="L1924" href="source/drivers/cpufreq/cpufreq.c#L1924">1924</a> 
<a name="L1925" href="source/drivers/cpufreq/cpufreq.c#L1925">1925</a>         if (<a href="ident?i=cpufreq_disabled">cpufreq_disabled</a>())
<a name="L1926" href="source/drivers/cpufreq/cpufreq.c#L1926">1926</a>                 return -<a href="ident?i=ENODEV">ENODEV</a>;
<a name="L1927" href="source/drivers/cpufreq/cpufreq.c#L1927">1927</a> 
<a name="L1928" href="source/drivers/cpufreq/cpufreq.c#L1928">1928</a>         <a href="ident?i=for_each_possible_cpu">for_each_possible_cpu</a>(<a href="ident?i=cpu">cpu</a>) {
<a name="L1929" href="source/drivers/cpufreq/cpufreq.c#L1929">1929</a>                 <a href="ident?i=per_cpu">per_cpu</a>(cpufreq_policy_cpu, <a href="ident?i=cpu">cpu</a>) = -1;
<a name="L1930" href="source/drivers/cpufreq/cpufreq.c#L1930">1930</a>                 <a href="ident?i=init_rwsem">init_rwsem</a>(&amp;<a href="ident?i=per_cpu">per_cpu</a>(cpu_policy_rwsem, <a href="ident?i=cpu">cpu</a>));
<a name="L1931" href="source/drivers/cpufreq/cpufreq.c#L1931">1931</a>         }
<a name="L1932" href="source/drivers/cpufreq/cpufreq.c#L1932">1932</a> 
<a name="L1933" href="source/drivers/cpufreq/cpufreq.c#L1933">1933</a>         <a href="ident?i=cpufreq_global_kobject">cpufreq_global_kobject</a> = <a href="ident?i=kobject_create_and_add">kobject_create_and_add</a>(<i>"cpufreq"</i>, &amp;<a href="ident?i=cpu_subsys">cpu_subsys</a>.<a href="ident?i=dev_root">dev_root</a>-&gt;<a href="ident?i=kobj">kobj</a>);
<a name="L1934" href="source/drivers/cpufreq/cpufreq.c#L1934">1934</a>         <a href="ident?i=BUG_ON">BUG_ON</a>(!<a href="ident?i=cpufreq_global_kobject">cpufreq_global_kobject</a>);
<a name="L1935" href="source/drivers/cpufreq/cpufreq.c#L1935">1935</a>         <a href="ident?i=register_syscore_ops">register_syscore_ops</a>(&amp;<a href="ident?i=cpufreq_syscore_ops">cpufreq_syscore_ops</a>);
<a name="L1936" href="source/drivers/cpufreq/cpufreq.c#L1936">1936</a> 
<a name="L1937" href="source/drivers/cpufreq/cpufreq.c#L1937">1937</a>         return 0;
<a name="L1938" href="source/drivers/cpufreq/cpufreq.c#L1938">1938</a> }
<a name="L1939" href="source/drivers/cpufreq/cpufreq.c#L1939">1939</a> <a href="ident?i=core_initcall">core_initcall</a>(<a href="ident?i=cpufreq_core_init">cpufreq_core_init</a>);
<a name="L1940" href="source/drivers/cpufreq/cpufreq.c#L1940">1940</a> </pre></div><p>
This page was automatically generated by <a href="http://lxr.linux.no">LXR</a> 0.3.1 (<a href="http://free-electrons.com/pub/source/lxr-0.3.1-fe1.tar.bz2">source</a>).
&nbsp;&bull;&nbsp;
Linux is a registered trademark of Linus Torvalds
</p>

<div id="menu">
<ul>
   <li><a href="http://free-electrons.com/">Home</a></li>
   <li><a href="http://free-electrons.com/development/" title="Development">Development</a></li>
   <li><a href="http://free-electrons.com/services/" title="Services">Services</a></li>
   <li><a href="http://free-electrons.com/training/" title="Training">Training</a></li>
   <li><a href="http://free-electrons.com/docs/" title="Docs">Docs</a></li>
   <li><a href="http://free-electrons.com/community/" title="Community">Community</a></li>
   <li><a href="http://free-electrons.com/company/" title="Company">Company</a></li>
   <li><a href="http://free-electrons.com/blog/" title="Blog">Blog</a></li>
</ul>
</div>

</div>
</div>
</body>
</html>
