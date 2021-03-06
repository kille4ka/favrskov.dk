<?php

/**
 * @file
 *  TODO
 */

/**
 * Implements hook_variable_group_info().
 */
function apachesolr_confgen_advanced_settings_variable_group_info() {
  $groups['apachesolr_confgen_advanced_settings'] = array(
    'title' => t('Apache Solr Advanced Settings'),
    'description' => t('Adjustable advanced parameters of the configuration files generated by Apache Solr Config Generator module'),
    'access' => 'administer search',
    'path' => array('admin/config/search/apachesolr/advanced_settings'),
  );

  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function apachesolr_confgen_advanced_settings_variable_info($options) {
  $variables['apachesolr_confgen_advanced_settings_disable_dataDir'] = array(
    'type' => 'boolean',
    'title' => t('Disable Data Dir setting', array(), $options),
    'default' => TRUE,
    'description' => t('Removes the dataDir property from solrconfig.xml. This might be useful for Solr multi core setups, or if you want to use Solr\'s default data dir location. See !link for further instructions.', array('!link' => l(t('Core Administration'), 'http://wiki.apache.org/solr/CoreAdmin')), $options) . apachesolr_confgen_get_required_version_string('1.4'),
    'group' => 'apachesolr_confgen_advanced_settings',
  );

  $variables['apachesolr_confgen_advanced_settings_dataDir'] = array(
    'type' => 'string',
    'title' => t('Data Dir', array(), $options),
    'default' => '${solr.data.dir:./solr/data}',
    'description' => t('Set an explicit path where solr stores the index like /var/sor/data for ubuntu linux', array(), $options),
    'group' => 'apachesolr_confgen_advanced_settings',
  );

  $variables['apachesolr_confgen_advanced_settings_autoCommit_maxTime'] = array(
    'type' => 'number',
    'title' => t('Auto Commit Max Time', array(), $options),
    'default' => 120000,
    'description' => t('Time in ms before documents posted to Solr will be committed to the index. This option is described as "delay" at !link.', array('!link' => l(t('Search Index'), 'admin/config/search/apachesolr/index')), $options) . apachesolr_confgen_get_required_version_string('1.4', $options),
    'required' => TRUE,
    'group' => 'apachesolr_confgen_advanced_settings',
  );

  $variables['apachesolr_confgen_advanced_settings_autoCommit_maxDocs'] = array(
    'type' => 'number',
    'title' => t('Auto Commit Max Docs', array(), $options),
    'default' => 10000,
    'description' => t('Maximum number of documents to add since the last commit before automatically triggering a new commit.', array(), $options) . apachesolr_confgen_get_required_version_string('1.4', $options),
    'required' => TRUE,
    'group' => 'apachesolr_confgen_advanced_settings',
  );

  $variables['apachesolr_confgen_advanced_settings_autoSoftCommit_maxTime'] = array(
    'type' => 'number',
    'title' => t('Auto Soft Commit Max Time', array(), $options),
    'default' => 10000,
    'description' => t('Time in ms before documents posted to Solr will be committed to the index. Like Auto Commit except it causes a "soft" commit which only ensures that changes are visible but does not ensure that data is synced to disk. This is faster and more near-realtime friendly than a hard commit.') . apachesolr_confgen_get_required_version_string('4.x', $options),
    'required' => TRUE,
    'group' => 'apachesolr_confgen_advanced_settings',
  );

  $variables['apachesolr_confgen_advanced_settings_autoSoftCommit_maxDocs'] = array(
    'type' => 'number',
    'title' => t('Auto Soft Commit Max Docs', array(), $options),
    'default' => 2000,
    'description' => t('Maximum number of documents to add since the last commit before automatically triggering a new commit. Like Auto Commit except it causes a "soft" commit which only ensures that changes are visible but does not ensure that data is synced to disk. This is faster and more near-realtime friendly than a hard commit.') . apachesolr_confgen_get_required_version_string('4.x', $options),
    'required' => TRUE,
    'group' => 'apachesolr_confgen_advanced_settings',
  );

  $variables['apachesolr_confgen_advanced_settings_mlt_timeAllowed'] = array(
    'type' => 'number',
    'title' => t('"More Like This" Time Allowed', array(), $options),
    'default' => 2000,
    'description' => t('Time in ms', array(), $options) . apachesolr_confgen_get_required_version_string('3.x', $options),
    'required' => TRUE,
    'group' => 'apachesolr_confgen_advanced_settings',
  );

  $variables['apachesolr_confgen_advanced_settings_replication_master'] = array(
    'type' => 'boolean',
    'solr_format' => 'string',
    'title' => t('Replication Master', array(), $options),
    'default' => FALSE,
    'description' => apachesolr_confgen_get_required_version_string('3.x', $options),
    'required' => FALSE,
    'group' => 'apachesolr_confgen_advanced_settings',
  );

  $variables['apachesolr_confgen_advanced_settings_replication_slave'] = array(
    'type' => 'boolean',
    'solr_format' => 'string',
    'title' => t('Replication Slave', array(), $options),
    'default' => FALSE,
    'description' => apachesolr_confgen_get_required_version_string('3.x', $options),
    'required' => FALSE,
    'group' => 'apachesolr_confgen_advanced_settings',
  );

  $variables['apachesolr_confgen_advanced_settings_replication_pollInterval'] = array(
    'type' => 'number',
    'title' => t('Replication Slave', array(), $options),
    'default' => 60,
    'description' => t('Poll interval in seconds', array(), $options) . apachesolr_confgen_get_required_version_string('3.x', $options),
    'required' => TRUE,
    'group' => 'apachesolr_confgen_advanced_settings',
  );

  $variables['apachesolr_confgen_advanced_settings_replication_masterUrl'] = array(
    'type' => 'string',
    'title' => t('Replication Master URL', array(), $options),
    'default' => 'http://localhost:8983/solr',
    'description' => apachesolr_confgen_get_required_version_string('3.x', $options),
    'required' => TRUE,
    'group' => 'apachesolr_confgen_advanced_settings',
  );

  return $variables;
}
