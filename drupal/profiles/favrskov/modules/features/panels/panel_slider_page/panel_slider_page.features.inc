<?php
/**
 * @file
 * panel_slider_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function panel_slider_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
